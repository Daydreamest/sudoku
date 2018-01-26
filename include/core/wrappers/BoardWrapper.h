#ifndef BOARDWRAPPER_H
#define BOARDWRAPPER_H

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>
#include <Slot.h>

class BoardWrapper
{
    public:
        BoardWrapper();
        virtual ~BoardWrapper();

        void set_value(const Slot slot);

        const FieldColumn& operator[](const size_t x) const;

        AbstractWrapper::handle_type get_row(const size_t y) const;
        AbstractWrapper::handle_type get_column(const size_t x) const;
        AbstractWrapper::handle_type get_tile(const size_t index) const;
        AbstractWrapper::handle_type get_tile(const Position pos) const;

    protected:

    private:
        FieldBoard board;

        const FieldRow create_empty_row() const;
        const FieldBoard create_empty_array() const;
};

#endif // BOARDWRAPPER_H
