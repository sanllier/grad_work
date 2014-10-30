#ifndef QERROR_H
#define QERROR_H

#include "mpi.h"

//-----------------------------------------------------------

namespace QError {
//-----------------------------------------------------------

class QError;

struct QErrorCtx
{
friend class QError;

private:
    bool initialized;

public:
    MPI_Comm matMulComm;
    int mmcRank;
    int mcwRank;
    int mmcSize;
    int mcwSize;
    int mmcCoords[2];

    QErrorCtx()
        : initialized( false ) 
        , matMulComm( MPI_COMM_NULL )
        , mmcRank(0)
        , mcwRank(0)
    {}

    inline bool isInitialized() { return initialized; }
};

//----------------------------------------------------------

class QError
{
private:
    QError() {}

public:
    static QErrorCtx createContext( int nproc = 0 );

private:

};

//-----------------------------------------------------------
}

//-----------------------------------------------------------
#endif
