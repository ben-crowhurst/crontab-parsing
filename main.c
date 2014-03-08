#include <pwd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <uuid/uuid.h>

#define MAIN_PROGRAM 1
#include "cron-3.0pl1.orig/cron.h"

void error_handler( char* message )
{
    fprintf( stderr, "Error: %s\n", message );
}

void print_entry( const entry* e )
{
    fprintf( stdout, "uid: %i\n", e->uid );
    fprintf( stdout, "gid: %i\n", e->gid );
    fprintf( stdout, "command: %s\n", e->cmd);
    //etc...
}

int main( int argc, char** argv, char** envp )
{
    const char* filename = "crontab";
    const char* username = "corvusoft";

    //Retreive Crontab File
    FILE *file = fopen( filename, "r" );

    if ( file == NULL )
    {
        error_handler( strerror( errno ) );

        return EXIT_FAILURE;
    }

    //Retreive Password Entry
    struct passwd *pw = getpwnam( username );

    if ( pw == NULL )
    {
        error_handler( strerror( errno ) );

        return EXIT_FAILURE;
    }

    //Read Entry
    entry *e = load_entry( file, &error_handler, pw, envp );

    if ( e == NULL )
    {
        error_handler( "No entry found!" );

        return EXIT_FAILURE;
    }

    print_entry( e );

    //Clean-up
    fclose( file );
    free_entry( e );

    return EXIT_SUCCESS;
}
