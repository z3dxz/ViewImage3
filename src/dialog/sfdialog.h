// 2/9/2025
#pragma once
#include <iostream>
#include <string>
#include "../IncludeSFML.h"

class Dialog {
public:
    enum ReturnCode {
        R_UNDEFINED,
        R_ERROR,
        R_YES,
        R_NO,
        R_OK,
        R_WARNED,
        R_CLOSED,
    };

    enum DialogMode {
        OK,
        ERR,
        YESNO,
        WARN,
    };
private:


    class sfDialog {
    private:

        ReturnCode globalReturn = R_UNDEFINED;

        sf::Uint32 windowstyle;
        std::string windowtitle = "";
        std::string windowdescription = "";

        class Btn {
        public:
            int order;
            std::string txt="";
            sf::Vector2f _position;
            sf::Vector2f _size;
            sf::RectangleShape _r;
            sf::Text _btn_txt;
            bool _hoverstate = false;
            bool _pressstate = false;
            bool _clickedstate = false;

            bool(*Action)(sfDialog*) = nullptr;
        };

        int width = 250;
        sf::Font dialogfont;
        sf::RectangleShape icon;
        sf::Text desctxt;
        sf::RectangleShape container;
        sf::RenderWindow window;

        std::vector<Btn> buttons;

        int calcOff(Btn& c_button);

        void renderButton(Btn& b);

        static bool closeYes(sfDialog* dialog);
        static bool closeNo(sfDialog* dialog);
        static bool closeOK(sfDialog* dialog);
        static bool closeWARNED(sfDialog* dialog);
    public:


        sfDialog(const std::string& title, const std::string& description, const DialogMode& mode, sf::Uint32 style);

        ReturnCode showDialog();
   
    };

public:
    static ReturnCode newDialog(const std::string title, const std::string description, const DialogMode mode, sf::Uint32 style = sf::Style::Close);
    
};