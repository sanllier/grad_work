#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <ostream>

//-----------------------------------------------------------

class Exception
{
public:
    Exception( const char* what, const char* loc )
        : m_what( what )
        , m_where( loc )
    {}
    virtual ~Exception() {}

    inline std::string getWhat() const { return m_what; }
    inline std::string getWhere() const { return m_where; }

    virtual std::ostream& operator<<( std::ostream& oStr ) const
    {
        oStr << m_what << ". " << m_where;
        return oStr;
    }

protected:
    std::string m_what;
    std::string m_where;
};

//-----------------------------------------------------------

class MPIException : public Exception
{
public:
    MPIException( const char* what, const char* loc )
        : Exception( what, loc )
    {}
    ~MPIException() {}
};

//-----------------------------------------------------------
#endif
