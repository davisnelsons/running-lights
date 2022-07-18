#ifndef ONOFFLEDMODEL_H
#define ONOFFLEDMODEL_H

template <typename Display>
class OnOffLEDModel
{
    public:
        OnOffLEDModel();
        bool getState() const;
        void setState(const bool state);
        void attachDisplay(Display * display);
        void updateDisplay() const;
    private:
        Display * display;
        bool state;
};

#endif