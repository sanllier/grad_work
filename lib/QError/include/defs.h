#ifndef DEFS_H
#define DEFS_H

//-----------------------------------------------------------

#define checkres( _res_ )                                 \
    if ( _res_ != MPI_SUCCESS )                           \
    {                                                     \
        char errString[ MPI_MAX_ERROR_STRING ];           \
        int len;                                          \
        MPI_Error_string( _res_, errString, &len );       \
        throw MPIException( errString, __FUNCTION__ );    \
    }                                                     \

//----------------------------------------------------------

enum
{
    ROOT = 0
};

//----------------------------------------------------------

#define MASTERPRINT( _x_ )           \
    {                           \
        std::cout << _x_;       \
        std::cout.flush();      \
    }                           \

//-----------------------------------------------------------
#endif
