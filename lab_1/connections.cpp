#include "connections.h"

static err_t allocate_connections(connections_t &connections)
{
    if (connections.amount <= 0)
        return AMOUNT_OF_CONNECTIONS_WRONG;

    connection_t *temp_arr = (connection_t*) malloc(connections.amount * sizeof(connection_t));
    if (!temp_arr)
        return MEMORY_ALLOCATION_ERROR;

    connections.arr_connect = temp_arr;

    return OK;
}

void free_connections(connections_t &connections)
{
    free(connections.arr_connect);

    connections.arr_connect = NULL;
    connections.amount = 0;
}

static err_t read_connection(connection_t &connection, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (fscanf(f, "%d %d", &connection.one_point,
                           &connection.two_point) != 2)
        return READ_FILE_ERROR;

    return OK;
}

static err_t read_connections(connections_t &connections, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;
    else if (connections.amount <= 0)
        return AMOUNT_OF_CONNECTIONS_WRONG;
    else if (!connections.arr_connect)
        return MEMORY_ALLOCATION_ERROR;

    err_t rc = OK;

    for (int i = 0; rc == OK && i < connections.amount; i++)
        rc = read_connection(connections.arr_connect[i], f);

    return rc;
}

err_t read_all_about_connections(connections_t &connections, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    err_t rc = read_amount(connections.amount, f);
    if (rc)
        return rc;

    rc = allocate_connections(connections);
    if (rc)
        return rc;

    rc = read_connections(connections, f);
    if (rc)
        free_connections(connections);

    return OK;
}
