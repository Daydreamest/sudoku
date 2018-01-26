#ifndef ALGORITHMROWS_H
#define ALGORITHMROWS_H

#include <AbstractAlgorithm.h>
#include <AbstractWrapper.h>

class AlgorithmRows : public AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AlgorithmRows>;

        static handle_type create(const FieldBoard& brd, SlotSet& res);

        virtual ~AlgorithmRows();

        virtual void operator()();

        virtual std::string get_name();

    protected:
        AlgorithmRows(const FieldBoard& brd, SlotSet& res);

    private:
        //TODO move to board wrapper
        AbstractWrapper::handle_type get_row(const size_t y) const;

};

#endif // ALGORITHMROWS_H
