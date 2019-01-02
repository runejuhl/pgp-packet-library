#include "dsa_secret_key.h"


namespace pgp {

    /**
     *  Constructor
     *
     *  @param  parser  The decoder to parse the data
     */
    dsa_secret_key::dsa_secret_key(decoder &parser) :
        _x{ parser }
    {}

    /**
     *  Constructor
     *
     *  @param  x   The secret exponent
     */
    dsa_secret_key::dsa_secret_key(multiprecision_integer x) noexcept :
        _x{ std::move(x) }
    {}

    /**
     *  Determine the size used in encoded format
     *  @return The number of bytes used for encoded storage
     */
    size_t dsa_secret_key::size() const noexcept
    {
        // we need to encode the secret exponent
        return _x.size();
    }

    /**
     *  Retrieve the secret exponent
     *
     *  @return The secret exponent x
     */
    const multiprecision_integer &dsa_secret_key::x() const noexcept
    {
        // return the secret exponent
        return _x;
    }

    /**
     *  Write the data to an encoder
     *
     *  @param  writer  The encoder to write to
     *  @throws std::out_of_range, std::range_error
     */
    void dsa_secret_key::encode(encoder &writer) const
    {
        // encode the secret exponent
        _x.encode(writer);
    }

}
