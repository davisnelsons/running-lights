#include "AbstractLEDModel.h"

class OnOffLEDModel : public AbstractLEDModel
{
    public:
        OnOffLEDModel();
        bool getState() 
        {
            return this->state;
        }
        void setState(bool state) 
        {
            this->state = state;
        }
        void attachDisplay()
        {
            ;;
        }
};