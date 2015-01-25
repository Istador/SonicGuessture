#ifndef LINESEQ_H
#define LINESEQ_H

#include <vector>
#include "shape.h"
#include "union.h"
#include "line.h"

typedef std::vector<pt> pts;

/**
 * @brief a line sequence, consisting of lines between following points
 */
class LineSeq : public Union {
public:
    LineSeq(pts points, bool closed = false);
};

#endif // LINESEQ_H
