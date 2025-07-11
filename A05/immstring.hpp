#pragma once

// An immutable string is a string whose contents can not be changed after creation.

/* TODO: Complete the class ImmutableString
 * * Update the given signatures with references where applicable to prevent 
 *   unnecessary copies.
 * * Add `const` where it makes sense, especially to prevent the string's 
 *   content from being modified
 * * Implement the described functions
 * * Test the functionality and that the string contents can not be changed
 */

namespace Util {

class ImmutableString {
public:
    // Creates a immutable string as copy of another.
    // Only the signature is missing something.
    ImmutableString(const ImmutableString& str);

    // Constructs an ImmutableString from a string literal.
    // Allocates a new buffer and copies `src`.
    ImmutableString(const char* const src);

    // Free used memory.
    ~ImmutableString();

    // Creates a new string that contains the content of this followed by `other`.
    // The hinted private constructor might be useful.
    ImmutableString concat(ImmutableString const other) const;

    // Provide read-only access to the string's content.
    // This function is a good candidate for being defined in the header (inline)
    const char* const c_str() const {
        return m_data;
    };

    // Return the string's size (excluding the terminating `\x0` character).
    // This function is a good candidate for being defined in the header (inline)
    const int size() const {
        return m_size;
    };

private:
    // Construct a string from an already allocated buffer.
    // The string takes ownership of buf.
    // This constructor is private because it makes assumptions about the 
    // ownership of the memory pointed to by `buf`, which is not wise to expose
    // in the public interface of the class.
    ImmutableString(char* buf, int len);

    // Can you use `const` to restrict the usage of these private data members? 
    // Why should you?
    int   const m_size; // length of string/number of characters excluding `\x0`
    char* const m_data; // string including terminating `\x0` character
};

} // Util
