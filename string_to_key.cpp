#include "string_to_key.h"


namespace pgp {

    /**
     *  Constructor
     *
     *  @param  parser  The decoder to parse the data
     */
    string_to_key::string_to_key(decoder &parser) :
        _convention{ parser }
    {
        // @TODO: support other conventions than "nothing"
    }

    /**
     *  Determine the size used in encoded format
     *  @return The number of bytes used for encoded storage
     */
    size_t string_to_key::size() const noexcept
    {
        // return the size of the convention
        return _convention.size();
    }

    /**
     *  Retrieve the convention used
     *
     *  @return The string-to-key convention
     */
    uint8_t string_to_key::convention() const noexcept
    {
        // return the stored convention
        return _convention;
    }

    /**
     *  Write the data to an encoder
     *
     *  @param  writer  The encoder to write to
     *  @throws std::out_of_range, std::range_error
     */
    void string_to_key::encode(encoder &writer) const
    {
        // encode the convention
        _convention.encode(writer);
    }

}
