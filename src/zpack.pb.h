// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zpack.proto

#ifndef PROTOBUF_zpack_2eproto__INCLUDED
#define PROTOBUF_zpack_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_zpack_2eproto();
void protobuf_AssignDesc_zpack_2eproto();
void protobuf_ShutdownFile_zpack_2eproto();

class ZPack;

// ===================================================================

class ZPack : public ::google::protobuf::Message {
 public:
  ZPack();
  virtual ~ZPack();
  
  ZPack(const ZPack& from);
  
  inline ZPack& operator=(const ZPack& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ZPack& default_instance();
  
  void Swap(ZPack* other);
  
  // implements Message ----------------------------------------------
  
  ZPack* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ZPack& from);
  void MergeFrom(const ZPack& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional bytes opcode = 1;
  inline bool has_opcode() const;
  inline void clear_opcode();
  static const int kOpcodeFieldNumber = 1;
  inline const ::std::string& opcode() const;
  inline void set_opcode(const ::std::string& value);
  inline void set_opcode(const char* value);
  inline void set_opcode(const void* value, size_t size);
  inline ::std::string* mutable_opcode();
  inline ::std::string* release_opcode();
  
  // optional bytes key = 2;
  inline bool has_key() const;
  inline void clear_key();
  static const int kKeyFieldNumber = 2;
  inline const ::std::string& key() const;
  inline void set_key(const ::std::string& value);
  inline void set_key(const char* value);
  inline void set_key(const void* value, size_t size);
  inline ::std::string* mutable_key();
  inline ::std::string* release_key();
  
  // optional bytes val = 3;
  inline bool has_val() const;
  inline void clear_val();
  static const int kValFieldNumber = 3;
  inline const ::std::string& val() const;
  inline void set_val(const ::std::string& value);
  inline void set_val(const char* value);
  inline void set_val(const void* value, size_t size);
  inline ::std::string* mutable_val();
  inline ::std::string* release_val();
  
  // optional bytes newval = 4;
  inline bool has_newval() const;
  inline void clear_newval();
  static const int kNewvalFieldNumber = 4;
  inline const ::std::string& newval() const;
  inline void set_newval(const ::std::string& value);
  inline void set_newval(const char* value);
  inline void set_newval(const void* value, size_t size);
  inline ::std::string* mutable_newval();
  inline ::std::string* release_newval();
  
  // optional bytes lease = 5;
  inline bool has_lease() const;
  inline void clear_lease();
  static const int kLeaseFieldNumber = 5;
  inline const ::std::string& lease() const;
  inline void set_lease(const ::std::string& value);
  inline void set_lease(const char* value);
  inline void set_lease(const void* value, size_t size);
  inline ::std::string* mutable_lease();
  inline ::std::string* release_lease();
  
  // optional bool valnull = 6;
  inline bool has_valnull() const;
  inline void clear_valnull();
  static const int kValnullFieldNumber = 6;
  inline bool valnull() const;
  inline void set_valnull(bool value);
  
  // optional bool newvalnull = 7;
  inline bool has_newvalnull() const;
  inline void clear_newvalnull();
  static const int kNewvalnullFieldNumber = 7;
  inline bool newvalnull() const;
  inline void set_newvalnull(bool value);
  
  // optional int32 replicanum = 8;
  inline bool has_replicanum() const;
  inline void clear_replicanum();
  static const int kReplicanumFieldNumber = 8;
  inline ::google::protobuf::int32 replicanum() const;
  inline void set_replicanum(::google::protobuf::int32 value);
  
  // optional bytes client_ip = 9;
  inline bool has_client_ip() const;
  inline void clear_client_ip();
  static const int kClientIpFieldNumber = 9;
  inline const ::std::string& client_ip() const;
  inline void set_client_ip(const ::std::string& value);
  inline void set_client_ip(const char* value);
  inline void set_client_ip(const void* value, size_t size);
  inline ::std::string* mutable_client_ip();
  inline ::std::string* release_client_ip();
  
  // optional int32 client_port = 10;
  inline bool has_client_port() const;
  inline void clear_client_port();
  static const int kClientPortFieldNumber = 10;
  inline ::google::protobuf::int32 client_port() const;
  inline void set_client_port(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:ZPack)
 private:
  inline void set_has_opcode();
  inline void clear_has_opcode();
  inline void set_has_key();
  inline void clear_has_key();
  inline void set_has_val();
  inline void clear_has_val();
  inline void set_has_newval();
  inline void clear_has_newval();
  inline void set_has_lease();
  inline void clear_has_lease();
  inline void set_has_valnull();
  inline void clear_has_valnull();
  inline void set_has_newvalnull();
  inline void clear_has_newvalnull();
  inline void set_has_replicanum();
  inline void clear_has_replicanum();
  inline void set_has_client_ip();
  inline void clear_has_client_ip();
  inline void set_has_client_port();
  inline void clear_has_client_port();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* opcode_;
  ::std::string* key_;
  ::std::string* val_;
  ::std::string* newval_;
  ::std::string* lease_;
  bool valnull_;
  bool newvalnull_;
  ::google::protobuf::int32 replicanum_;
  ::std::string* client_ip_;
  ::google::protobuf::int32 client_port_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(10 + 31) / 32];
  
  friend void  protobuf_AddDesc_zpack_2eproto();
  friend void protobuf_AssignDesc_zpack_2eproto();
  friend void protobuf_ShutdownFile_zpack_2eproto();
  
  void InitAsDefaultInstance();
  static ZPack* default_instance_;
};
// ===================================================================


// ===================================================================

// ZPack

// optional bytes opcode = 1;
inline bool ZPack::has_opcode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ZPack::set_has_opcode() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ZPack::clear_has_opcode() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ZPack::clear_opcode() {
  if (opcode_ != &::google::protobuf::internal::kEmptyString) {
    opcode_->clear();
  }
  clear_has_opcode();
}
inline const ::std::string& ZPack::opcode() const {
  return *opcode_;
}
inline void ZPack::set_opcode(const ::std::string& value) {
  set_has_opcode();
  if (opcode_ == &::google::protobuf::internal::kEmptyString) {
    opcode_ = new ::std::string;
  }
  opcode_->assign(value);
}
inline void ZPack::set_opcode(const char* value) {
  set_has_opcode();
  if (opcode_ == &::google::protobuf::internal::kEmptyString) {
    opcode_ = new ::std::string;
  }
  opcode_->assign(value);
}
inline void ZPack::set_opcode(const void* value, size_t size) {
  set_has_opcode();
  if (opcode_ == &::google::protobuf::internal::kEmptyString) {
    opcode_ = new ::std::string;
  }
  opcode_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_opcode() {
  set_has_opcode();
  if (opcode_ == &::google::protobuf::internal::kEmptyString) {
    opcode_ = new ::std::string;
  }
  return opcode_;
}
inline ::std::string* ZPack::release_opcode() {
  clear_has_opcode();
  if (opcode_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = opcode_;
    opcode_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes key = 2;
inline bool ZPack::has_key() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ZPack::set_has_key() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ZPack::clear_has_key() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ZPack::clear_key() {
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    key_->clear();
  }
  clear_has_key();
}
inline const ::std::string& ZPack::key() const {
  return *key_;
}
inline void ZPack::set_key(const ::std::string& value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void ZPack::set_key(const char* value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void ZPack::set_key(const void* value, size_t size) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_key() {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  return key_;
}
inline ::std::string* ZPack::release_key() {
  clear_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = key_;
    key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes val = 3;
inline bool ZPack::has_val() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ZPack::set_has_val() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ZPack::clear_has_val() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ZPack::clear_val() {
  if (val_ != &::google::protobuf::internal::kEmptyString) {
    val_->clear();
  }
  clear_has_val();
}
inline const ::std::string& ZPack::val() const {
  return *val_;
}
inline void ZPack::set_val(const ::std::string& value) {
  set_has_val();
  if (val_ == &::google::protobuf::internal::kEmptyString) {
    val_ = new ::std::string;
  }
  val_->assign(value);
}
inline void ZPack::set_val(const char* value) {
  set_has_val();
  if (val_ == &::google::protobuf::internal::kEmptyString) {
    val_ = new ::std::string;
  }
  val_->assign(value);
}
inline void ZPack::set_val(const void* value, size_t size) {
  set_has_val();
  if (val_ == &::google::protobuf::internal::kEmptyString) {
    val_ = new ::std::string;
  }
  val_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_val() {
  set_has_val();
  if (val_ == &::google::protobuf::internal::kEmptyString) {
    val_ = new ::std::string;
  }
  return val_;
}
inline ::std::string* ZPack::release_val() {
  clear_has_val();
  if (val_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = val_;
    val_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes newval = 4;
inline bool ZPack::has_newval() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ZPack::set_has_newval() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ZPack::clear_has_newval() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ZPack::clear_newval() {
  if (newval_ != &::google::protobuf::internal::kEmptyString) {
    newval_->clear();
  }
  clear_has_newval();
}
inline const ::std::string& ZPack::newval() const {
  return *newval_;
}
inline void ZPack::set_newval(const ::std::string& value) {
  set_has_newval();
  if (newval_ == &::google::protobuf::internal::kEmptyString) {
    newval_ = new ::std::string;
  }
  newval_->assign(value);
}
inline void ZPack::set_newval(const char* value) {
  set_has_newval();
  if (newval_ == &::google::protobuf::internal::kEmptyString) {
    newval_ = new ::std::string;
  }
  newval_->assign(value);
}
inline void ZPack::set_newval(const void* value, size_t size) {
  set_has_newval();
  if (newval_ == &::google::protobuf::internal::kEmptyString) {
    newval_ = new ::std::string;
  }
  newval_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_newval() {
  set_has_newval();
  if (newval_ == &::google::protobuf::internal::kEmptyString) {
    newval_ = new ::std::string;
  }
  return newval_;
}
inline ::std::string* ZPack::release_newval() {
  clear_has_newval();
  if (newval_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = newval_;
    newval_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes lease = 5;
inline bool ZPack::has_lease() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ZPack::set_has_lease() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ZPack::clear_has_lease() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ZPack::clear_lease() {
  if (lease_ != &::google::protobuf::internal::kEmptyString) {
    lease_->clear();
  }
  clear_has_lease();
}
inline const ::std::string& ZPack::lease() const {
  return *lease_;
}
inline void ZPack::set_lease(const ::std::string& value) {
  set_has_lease();
  if (lease_ == &::google::protobuf::internal::kEmptyString) {
    lease_ = new ::std::string;
  }
  lease_->assign(value);
}
inline void ZPack::set_lease(const char* value) {
  set_has_lease();
  if (lease_ == &::google::protobuf::internal::kEmptyString) {
    lease_ = new ::std::string;
  }
  lease_->assign(value);
}
inline void ZPack::set_lease(const void* value, size_t size) {
  set_has_lease();
  if (lease_ == &::google::protobuf::internal::kEmptyString) {
    lease_ = new ::std::string;
  }
  lease_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_lease() {
  set_has_lease();
  if (lease_ == &::google::protobuf::internal::kEmptyString) {
    lease_ = new ::std::string;
  }
  return lease_;
}
inline ::std::string* ZPack::release_lease() {
  clear_has_lease();
  if (lease_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = lease_;
    lease_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bool valnull = 6;
inline bool ZPack::has_valnull() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ZPack::set_has_valnull() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ZPack::clear_has_valnull() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ZPack::clear_valnull() {
  valnull_ = false;
  clear_has_valnull();
}
inline bool ZPack::valnull() const {
  return valnull_;
}
inline void ZPack::set_valnull(bool value) {
  set_has_valnull();
  valnull_ = value;
}

// optional bool newvalnull = 7;
inline bool ZPack::has_newvalnull() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ZPack::set_has_newvalnull() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ZPack::clear_has_newvalnull() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ZPack::clear_newvalnull() {
  newvalnull_ = false;
  clear_has_newvalnull();
}
inline bool ZPack::newvalnull() const {
  return newvalnull_;
}
inline void ZPack::set_newvalnull(bool value) {
  set_has_newvalnull();
  newvalnull_ = value;
}

// optional int32 replicanum = 8;
inline bool ZPack::has_replicanum() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void ZPack::set_has_replicanum() {
  _has_bits_[0] |= 0x00000080u;
}
inline void ZPack::clear_has_replicanum() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void ZPack::clear_replicanum() {
  replicanum_ = 0;
  clear_has_replicanum();
}
inline ::google::protobuf::int32 ZPack::replicanum() const {
  return replicanum_;
}
inline void ZPack::set_replicanum(::google::protobuf::int32 value) {
  set_has_replicanum();
  replicanum_ = value;
}

// optional bytes client_ip = 9;
inline bool ZPack::has_client_ip() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void ZPack::set_has_client_ip() {
  _has_bits_[0] |= 0x00000100u;
}
inline void ZPack::clear_has_client_ip() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void ZPack::clear_client_ip() {
  if (client_ip_ != &::google::protobuf::internal::kEmptyString) {
    client_ip_->clear();
  }
  clear_has_client_ip();
}
inline const ::std::string& ZPack::client_ip() const {
  return *client_ip_;
}
inline void ZPack::set_client_ip(const ::std::string& value) {
  set_has_client_ip();
  if (client_ip_ == &::google::protobuf::internal::kEmptyString) {
    client_ip_ = new ::std::string;
  }
  client_ip_->assign(value);
}
inline void ZPack::set_client_ip(const char* value) {
  set_has_client_ip();
  if (client_ip_ == &::google::protobuf::internal::kEmptyString) {
    client_ip_ = new ::std::string;
  }
  client_ip_->assign(value);
}
inline void ZPack::set_client_ip(const void* value, size_t size) {
  set_has_client_ip();
  if (client_ip_ == &::google::protobuf::internal::kEmptyString) {
    client_ip_ = new ::std::string;
  }
  client_ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ZPack::mutable_client_ip() {
  set_has_client_ip();
  if (client_ip_ == &::google::protobuf::internal::kEmptyString) {
    client_ip_ = new ::std::string;
  }
  return client_ip_;
}
inline ::std::string* ZPack::release_client_ip() {
  clear_has_client_ip();
  if (client_ip_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = client_ip_;
    client_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional int32 client_port = 10;
inline bool ZPack::has_client_port() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void ZPack::set_has_client_port() {
  _has_bits_[0] |= 0x00000200u;
}
inline void ZPack::clear_has_client_port() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void ZPack::clear_client_port() {
  client_port_ = 0;
  clear_has_client_port();
}
inline ::google::protobuf::int32 ZPack::client_port() const {
  return client_port_;
}
inline void ZPack::set_client_port(::google::protobuf::int32 value) {
  set_has_client_port();
  client_port_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_zpack_2eproto__INCLUDED
