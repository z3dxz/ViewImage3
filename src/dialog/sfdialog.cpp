#include "sfdialog.h"

int Dialog::sfDialog::calcOff(Btn& c_button) {
    int off = width;
    // iterate over all buttons
    for (int i = 0; i < buttons.size(); i++) {
        Btn& bi = buttons[i];
        if (bi.order < c_button.order) {
            off -= bi._size.x + 4;
        }
    }
    return off;
}

void Dialog::sfDialog::renderButton(Btn& b) {
    b._btn_txt.setPosition({ b._position.x + 10, b._position.y + 2 });
    b._position = { (float)calcOff(b) - b._size.x - 6, 60 };

    b._size = { b._btn_txt.getGlobalBounds().getSize().x + 22, 21 };

    b._btn_txt.setString(b.txt);
    b._btn_txt.setCharacterSize(12);
    b._btn_txt.setFont(dialogfont);

    
    sf::Color btn_fce{ 40, 40, 40 };
    sf::Color btn_bdr{ 0,0,0 };
    sf::Color btn_line{ 90,90,90 };
    sf::Color btn_line2{ 60, 60, 60 };

    sf::Color Hbtn_fce = { 50, 50, 50 };
    sf::Color Hbtn_bdr = { 0,0,0 };
    sf::Color Hbtn_line = { 120,120,120 };
    sf::Color Hbtn_line2 = { 70,70,70 };


    sf::Color fce = b._hoverstate ? Hbtn_fce : btn_fce;
    sf::Color bdr = b._hoverstate ? Hbtn_bdr : btn_bdr;
    sf::Color line = b._hoverstate ? Hbtn_line : btn_line;
    sf::Color line2 = b._hoverstate ? Hbtn_line2 : btn_line2;

    b._r.setPosition({ b._position.x + 3, b._position.y + 3 });
    b._r.setSize({ b._size.x - 6, b._size.y - 6 });
    b._r.setFillColor(fce);

    b._r.setOutlineColor(bdr);
    b._r.setOutlineThickness(3);

    window.draw(b._r);

    b._r.setOutlineColor(line);
    b._r.setOutlineThickness(2);

    window.draw(b._r);

    b._r.setOutlineColor(line2);
    b._r.setOutlineThickness(1);

    window.draw(b._r);

    window.draw(b._btn_txt);
}

bool Dialog::sfDialog::closeYes(sfDialog* dialog) {
    dialog->globalReturn = R_YES;
    dialog->window.close();
    return false;
}

bool Dialog::sfDialog::closeNo(sfDialog* dialog) {
    dialog->globalReturn = R_NO;
    dialog->window.close();
    return false;
}

bool Dialog::sfDialog::closeOK(sfDialog* dialog) {
    dialog->globalReturn = R_OK;
    dialog->window.close();
    return false;
}

bool Dialog::sfDialog::closeWARNED(sfDialog* dialog) {
    dialog->globalReturn = R_WARNED;
    dialog->window.close();
    return false;
}


Dialog::sfDialog::sfDialog(const std::string& title, const std::string& description, const DialogMode& mode, sf::Uint32 style) {

    windowtitle = title;
    windowdescription = description;
    windowstyle = style;
    
    // description text
    desctxt.setString("");
    desctxt.setFont(dialogfont);
    desctxt.setCharacterSize(12);
    desctxt.setPosition(52, 18);
    desctxt.setString(windowdescription);

    // icon
    icon.setSize({ 32,32 });
    icon.setPosition(10, 10);
    icon.setFillColor({ 200,50,50 });


    // container for buttons
    container.setPosition(0, 52);
    container.setSize({ (float)width, 41 });
    container.setFillColor({ 60, 60, 60 });

    // create buttons
    switch (mode) {
    case WARN: {
        Btn b;
        b.Action = closeWARNED;
        b.order = 1;
        b.txt = "OK";
        buttons.push_back(b);
        break;
    }
    case YESNO: {
        Btn y;
        y.Action = closeYes;
        y.order = 1;
        y.txt = "Yes";

        Btn n;
        n.Action = closeNo;
        n.order = 2;
        n.txt = "No";

        buttons.push_back(y);
        buttons.push_back(n);
        break;
    }
    default: 
    case OK: {
        Btn b;
        b.Action = closeOK;
        b.order = 1;
        b.txt = "OK";

        buttons.push_back(b);
        break;
    } 
    }

}

Dialog::ReturnCode Dialog::sfDialog::showDialog() {
    window.create(sf::VideoMode(width, 95), windowtitle, windowstyle);
    window.clear();
    window.setFramerateLimit(24);

    window.clear({ 0, 0, 0 });
    // load font object
    if (dialogfont.getInfo().family.empty()) {
        if (!dialogfont.loadFromFile("Lato-Regular.ttf")) {
            return R_ERROR;
        }
    }

    


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                globalReturn = R_CLOSED;
                window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                for (int i = 0; i < buttons.size(); i++) {
                    Btn& ib = buttons[i];
                    ib._hoverstate = false;
                    if (mousepos.x > ib._position.x && mousepos.x < (ib._position.x + ib._size.x)) {
                        if (mousepos.y > ib._position.y && mousepos.y < (ib._position.y + ib._size.y)) {
                            ib._hoverstate = true;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                for (int i = 0; i < buttons.size(); i++) {
                    Btn& ib = buttons[i];
                    if (mousepos.x > ib._position.x && mousepos.x < (ib._position.x + ib._size.x)) {
                        if (mousepos.y > ib._position.y && mousepos.y < (ib._position.y + ib._size.y)) {
                            if (ib.Action != nullptr) {
                                ib.Action(this);
                            }
                            else {
                                Beep(400, 50);
                            }
                        }
                    }
                }
            }
        }

        window.clear({ 50,50,50 });
        window.draw(desctxt);


        container.setOutlineColor({ 0,0,0 });
        container.setOutlineThickness(2);
        window.draw(container);

        container.setOutlineColor({ 100,100,100 });
        container.setOutlineThickness(1);
        window.draw(container);

        window.draw(icon);

        for (Btn& i : buttons) {
            renderButton(i);
        }
                

        window.display();
    }

    return globalReturn;
}

Dialog::ReturnCode Dialog::newDialog(const std::string title, const std::string description, const DialogMode mode, sf::Uint32 style) {
    sfDialog d(title, description, mode, style);
    ReturnCode res = d.showDialog();

    return res;
}
