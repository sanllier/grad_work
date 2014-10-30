#include "QError.h"
#include "exception.h"
#include "defs.h"

//-----------------------------------------------------------

namespace QError {
//----------------------------------------------------------

QErrorCtx QError::createContext( int nproc )
{
    int isMPIInitialized = 0;
    checkres( MPI_Initialized( &isMPIInitialized ) );
    if ( !isMPIInitialized )
        checkres( MPI_Init( 0, 0 ) );

    QErrorCtx ctx;

    checkres( MPI_Comm_rank( MPI_COMM_WORLD, &ctx.mcwRank ) );
    checkres( MPI_Comm_size( MPI_COMM_WORLD, &ctx.mcwSize ) );

}

//-----------------------------------------------------------
}
