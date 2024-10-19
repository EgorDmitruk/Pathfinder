#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

bool are_edges_equal(int *edge1, int *edge2) {
    return (edge1[0] == edge2[0] && edge1[1] == edge2[1]) || (edge1[0] == edge2[1] && edge1[1] == edge2[0]);
}
