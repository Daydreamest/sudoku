#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <memory>

#include <AbstractData.h>
#include <Matrix.h>
#include <Position.h>

class UiData : public AbstractData
{
    public:
        using handle_type = std::shared_ptr<UiData>;

        static handle_type create();
        virtual ~UiData();

        void set_value(const size_t x, const size_t y, const char value);

        virtual char get_value(const Position pos) const override;

        void reset();

    protected:
        UiData();

    private:
        Table<char> data;

        const Table<char> create_empty_array() const;
};

#endif // SUDOKUDATA_H
