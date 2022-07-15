#include <cstdint>
class AbstractLEDModel
{
    protected:
        bool state {false};
    public:
        AbstractLEDModel();
        virtual void setState(bool state) = 0;
        virtual bool getState() = 0;
        virtual void attachDisplay() = 0;
};