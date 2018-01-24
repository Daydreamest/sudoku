#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include <memory>

#include <Slot.h>
#include <Field.h>

class AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AbstractAlgorithm>;

        AbstractAlgorithm(FieldBoard brd, SlotSet& res);
        virtual ~AbstractAlgorithm();

        virtual void operator()() = 0;

        virtual std::string get_name() = 0;
    protected:

    private:
        const FieldBoard board;
        SlotSet& results;
};

#endif // ABSTRACTALGORITHM_H
