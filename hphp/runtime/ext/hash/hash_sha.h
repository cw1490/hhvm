/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXT_HASH_SHA_H_
#define incl_HPHP_EXT_HASH_SHA_H_

#include "hphp/runtime/ext/hash/hash_engine.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

struct hash_sha1 : HashEngine {
  hash_sha1();

  virtual void hash_init(void *context);
  virtual void hash_update(void *context, const unsigned char *buf,
                           unsigned int count);
  virtual void hash_final(unsigned char *digest, void *context);
};

struct hash_sha256 : HashEngine {
  explicit hash_sha256(int size = 32);

  virtual void hash_init(void *context);
  virtual void hash_update(void *context, const unsigned char *buf,
                           unsigned int count);
  virtual void hash_final(unsigned char *digest, void *context);
};

/* sha224 is just sha256 with a different initial vector
 * and a truncated output.
 */
struct hash_sha224 : hash_sha256 {
  hash_sha224() : hash_sha256(28) {}

  virtual void hash_init(void *context);
  virtual void hash_final(unsigned char *digest, void *context);
};

struct hash_sha384 : HashEngine {
  hash_sha384();

  virtual void hash_init(void *context);
  virtual void hash_update(void *context, const unsigned char *buf,
                           unsigned int count);
  virtual void hash_final(unsigned char *digest, void *context);
};

struct hash_sha512 : HashEngine {
  hash_sha512();

  virtual void hash_init(void *context);
  virtual void hash_update(void *context, const unsigned char *buf,
                           unsigned int count);
  virtual void hash_final(unsigned char *digest, void *context);
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_HASH_SHA_H_
