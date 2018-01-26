#ifndef ALGORITHMFIELDS_H
#define ALGORITHMFIELDS_H

#include <AbstractAlgorithm.h>

class AlgorithmFields : public AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AlgorithmFields>;

        static handle_type create(BoardWrapper& brd, SlotSet& res);
        virtual ~AlgorithmFields();

        virtual void operator()();

        virtual std::string get_name();

    protected:
        AlgorithmFields(BoardWrapper& brd, SlotSet& res);

    private:
};

#endif // ALGORITHMFIELDS_H