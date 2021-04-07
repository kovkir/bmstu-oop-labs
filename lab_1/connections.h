#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <cstdio>
#include <cstdlib>

#include "points.h"
#include "data.h"
#include "err.h"

void free_connections(connections_t &connections);

err_t read_all_about_connections(connections_t &connections, FILE *f);

#endif
