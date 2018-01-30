#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <memory>

#include <AbstractData.h>
#include <Matrix.h>
#include <Position.h>

namespace sudoku {
namespace ui {

class UiData : public AbstractData
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<UiData>;

        // Building method
        static handle_type create();

        // Destructor
        virtual ~UiData();

        // Value setter for a specific position
        void set_value(const Position pos, const char value);

        // AbstractData::get_value
        virtual const char get_value(const Position pos) const override;

    protected:
        // Constructor
        UiData();

    private:
        // Creator of a default, empty data table
        Table<char> data;

        // Creator of a default, empty data table
        const Table<char> create_empty_array() const;
};

} //namespace ui
} // namespace sudoku

#endif // SUDOKUDATA_H
