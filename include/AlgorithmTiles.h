#ifndef ALGORITHMTILES_H
#define ALGORITHMTILES_H

#include <AbstractAlgorithm.h>

class AlgorithmTiles : public AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AlgorithmTiles>;

        static handle_type create(BoardWrapper& brd, SlotSet& res);

        virtual ~AlgorithmTiles();

        virtual void operator()();

        virtual std::string get_name();

    protected:
        AlgorithmTiles(BoardWrapper& brd, SlotSet& res);

    private:
};

#endif // ALGORITHMTILES_H