#ifndef MANGLE_STREAM_AUDIERECLIENT_H
#define MANGLE_STREAM_AUDIERECLIENT_H

#include <audiere.h>
#include <assert.h>

#include "../stream.hpp"

namespace Mangle {
namespace Stream {

/** @brief An Audiere::File that wraps a Mangle::Stream input.

    This lets Audiere read sound files from any generic archive or
    file manager that supports Mangle streams.
 */
class AudiereFile : public audiere::RefImplementation<audiere::File>
{
  StreamPtr inp;

 public:
  AudiereFile(StreamPtr _inp)
    : inp(_inp) {}

  /// Read 'count' bytes, return bytes successfully read
  int ADR_CALL read(void *buf, int count)
    { return inp->read(buf,count); }

  /// Seek, relative to specified seek mode. Returns true if successful.
  bool ADR_CALL seek(int pos, audiere::File::SeekMode mode);

  /// Get current position
  int ADR_CALL tell()
    { assert(inp->hasPosition); return inp->tell(); }
};

}} // namespaces
#endif
