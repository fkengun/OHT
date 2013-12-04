// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "zpack.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ZPack_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ZPack_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_zpack_2eproto() {
  protobuf_AddDesc_zpack_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "zpack.proto");
  GOOGLE_CHECK(file != NULL);
  ZPack_descriptor_ = file->message_type(0);
  static const int ZPack_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, client_ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, client_port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, seq_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, opcode_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, val_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, newval_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, lease_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, valnull_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, newvalnull_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, replicanum_),
  };
  ZPack_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ZPack_descriptor_,
      ZPack::default_instance_,
      ZPack_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ZPack, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ZPack));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_zpack_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ZPack_descriptor_, &ZPack::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_zpack_2eproto() {
  delete ZPack::default_instance_;
  delete ZPack_reflection_;
}

void protobuf_AddDesc_zpack_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013zpack.proto\"\302\001\n\005ZPack\022\021\n\tclient_ip\030\001 \001"
    "(\014\022\023\n\013client_port\030\002 \001(\005\022\017\n\007seq_num\030\003 \001(\003"
    "\022\016\n\006opcode\030\004 \001(\014\022\013\n\003key\030\005 \001(\014\022\013\n\003val\030\006 \001"
    "(\014\022\016\n\006newval\030\007 \001(\014\022\r\n\005lease\030\010 \001(\014\022\017\n\007val"
    "null\030\t \001(\010\022\022\n\nnewvalnull\030\n \001(\010\022\022\n\nreplic"
    "anum\030\013 \001(\005", 210);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "zpack.proto", &protobuf_RegisterTypes);
  ZPack::default_instance_ = new ZPack();
  ZPack::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_zpack_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_zpack_2eproto {
  StaticDescriptorInitializer_zpack_2eproto() {
    protobuf_AddDesc_zpack_2eproto();
  }
} static_descriptor_initializer_zpack_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int ZPack::kClientIpFieldNumber;
const int ZPack::kClientPortFieldNumber;
const int ZPack::kSeqNumFieldNumber;
const int ZPack::kOpcodeFieldNumber;
const int ZPack::kKeyFieldNumber;
const int ZPack::kValFieldNumber;
const int ZPack::kNewvalFieldNumber;
const int ZPack::kLeaseFieldNumber;
const int ZPack::kValnullFieldNumber;
const int ZPack::kNewvalnullFieldNumber;
const int ZPack::kReplicanumFieldNumber;
#endif  // !_MSC_VER

ZPack::ZPack()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ZPack::InitAsDefaultInstance() {
}

ZPack::ZPack(const ZPack& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ZPack::SharedCtor() {
  _cached_size_ = 0;
  client_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  client_port_ = 0;
  seq_num_ = GOOGLE_LONGLONG(0);
  opcode_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  val_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  newval_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  lease_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  valnull_ = false;
  newvalnull_ = false;
  replicanum_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ZPack::~ZPack() {
  SharedDtor();
}

void ZPack::SharedDtor() {
  if (client_ip_ != &::google::protobuf::internal::kEmptyString) {
    delete client_ip_;
  }
  if (opcode_ != &::google::protobuf::internal::kEmptyString) {
    delete opcode_;
  }
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    delete key_;
  }
  if (val_ != &::google::protobuf::internal::kEmptyString) {
    delete val_;
  }
  if (newval_ != &::google::protobuf::internal::kEmptyString) {
    delete newval_;
  }
  if (lease_ != &::google::protobuf::internal::kEmptyString) {
    delete lease_;
  }
  if (this != default_instance_) {
  }
}

void ZPack::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ZPack::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ZPack_descriptor_;
}

const ZPack& ZPack::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_zpack_2eproto();  return *default_instance_;
}

ZPack* ZPack::default_instance_ = NULL;

ZPack* ZPack::New() const {
  return new ZPack;
}

void ZPack::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_client_ip()) {
      if (client_ip_ != &::google::protobuf::internal::kEmptyString) {
        client_ip_->clear();
      }
    }
    client_port_ = 0;
    seq_num_ = GOOGLE_LONGLONG(0);
    if (has_opcode()) {
      if (opcode_ != &::google::protobuf::internal::kEmptyString) {
        opcode_->clear();
      }
    }
    if (has_key()) {
      if (key_ != &::google::protobuf::internal::kEmptyString) {
        key_->clear();
      }
    }
    if (has_val()) {
      if (val_ != &::google::protobuf::internal::kEmptyString) {
        val_->clear();
      }
    }
    if (has_newval()) {
      if (newval_ != &::google::protobuf::internal::kEmptyString) {
        newval_->clear();
      }
    }
    if (has_lease()) {
      if (lease_ != &::google::protobuf::internal::kEmptyString) {
        lease_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    valnull_ = false;
    newvalnull_ = false;
    replicanum_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ZPack::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes client_ip = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_client_ip()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_client_port;
        break;
      }
      
      // optional int32 client_port = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_port:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_port_)));
          set_has_client_port();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_seq_num;
        break;
      }
      
      // optional int64 seq_num = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_seq_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &seq_num_)));
          set_has_seq_num();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_opcode;
        break;
      }
      
      // optional bytes opcode = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_opcode:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_opcode()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_key;
        break;
      }
      
      // optional bytes key = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_key()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_val;
        break;
      }
      
      // optional bytes val = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_val:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_val()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_newval;
        break;
      }
      
      // optional bytes newval = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_newval:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_newval()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_lease;
        break;
      }
      
      // optional bytes lease = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_lease:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_lease()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_valnull;
        break;
      }
      
      // optional bool valnull = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_valnull:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &valnull_)));
          set_has_valnull();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_newvalnull;
        break;
      }
      
      // optional bool newvalnull = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_newvalnull:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &newvalnull_)));
          set_has_newvalnull();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_replicanum;
        break;
      }
      
      // optional int32 replicanum = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_replicanum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &replicanum_)));
          set_has_replicanum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ZPack::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional bytes client_ip = 1;
  if (has_client_ip()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->client_ip(), output);
  }
  
  // optional int32 client_port = 2;
  if (has_client_port()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->client_port(), output);
  }
  
  // optional int64 seq_num = 3;
  if (has_seq_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->seq_num(), output);
  }
  
  // optional bytes opcode = 4;
  if (has_opcode()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->opcode(), output);
  }
  
  // optional bytes key = 5;
  if (has_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      5, this->key(), output);
  }
  
  // optional bytes val = 6;
  if (has_val()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->val(), output);
  }
  
  // optional bytes newval = 7;
  if (has_newval()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->newval(), output);
  }
  
  // optional bytes lease = 8;
  if (has_lease()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      8, this->lease(), output);
  }
  
  // optional bool valnull = 9;
  if (has_valnull()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->valnull(), output);
  }
  
  // optional bool newvalnull = 10;
  if (has_newvalnull()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(10, this->newvalnull(), output);
  }
  
  // optional int32 replicanum = 11;
  if (has_replicanum()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->replicanum(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ZPack::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional bytes client_ip = 1;
  if (has_client_ip()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->client_ip(), target);
  }
  
  // optional int32 client_port = 2;
  if (has_client_port()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->client_port(), target);
  }
  
  // optional int64 seq_num = 3;
  if (has_seq_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->seq_num(), target);
  }
  
  // optional bytes opcode = 4;
  if (has_opcode()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->opcode(), target);
  }
  
  // optional bytes key = 5;
  if (has_key()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->key(), target);
  }
  
  // optional bytes val = 6;
  if (has_val()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->val(), target);
  }
  
  // optional bytes newval = 7;
  if (has_newval()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->newval(), target);
  }
  
  // optional bytes lease = 8;
  if (has_lease()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        8, this->lease(), target);
  }
  
  // optional bool valnull = 9;
  if (has_valnull()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->valnull(), target);
  }
  
  // optional bool newvalnull = 10;
  if (has_newvalnull()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(10, this->newvalnull(), target);
  }
  
  // optional int32 replicanum = 11;
  if (has_replicanum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->replicanum(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ZPack::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes client_ip = 1;
    if (has_client_ip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->client_ip());
    }
    
    // optional int32 client_port = 2;
    if (has_client_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_port());
    }
    
    // optional int64 seq_num = 3;
    if (has_seq_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->seq_num());
    }
    
    // optional bytes opcode = 4;
    if (has_opcode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->opcode());
    }
    
    // optional bytes key = 5;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->key());
    }
    
    // optional bytes val = 6;
    if (has_val()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->val());
    }
    
    // optional bytes newval = 7;
    if (has_newval()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->newval());
    }
    
    // optional bytes lease = 8;
    if (has_lease()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->lease());
    }
    
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool valnull = 9;
    if (has_valnull()) {
      total_size += 1 + 1;
    }
    
    // optional bool newvalnull = 10;
    if (has_newvalnull()) {
      total_size += 1 + 1;
    }
    
    // optional int32 replicanum = 11;
    if (has_replicanum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->replicanum());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ZPack::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ZPack* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ZPack*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ZPack::MergeFrom(const ZPack& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_client_ip()) {
      set_client_ip(from.client_ip());
    }
    if (from.has_client_port()) {
      set_client_port(from.client_port());
    }
    if (from.has_seq_num()) {
      set_seq_num(from.seq_num());
    }
    if (from.has_opcode()) {
      set_opcode(from.opcode());
    }
    if (from.has_key()) {
      set_key(from.key());
    }
    if (from.has_val()) {
      set_val(from.val());
    }
    if (from.has_newval()) {
      set_newval(from.newval());
    }
    if (from.has_lease()) {
      set_lease(from.lease());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_valnull()) {
      set_valnull(from.valnull());
    }
    if (from.has_newvalnull()) {
      set_newvalnull(from.newvalnull());
    }
    if (from.has_replicanum()) {
      set_replicanum(from.replicanum());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ZPack::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ZPack::CopyFrom(const ZPack& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ZPack::IsInitialized() const {
  
  return true;
}

void ZPack::Swap(ZPack* other) {
  if (other != this) {
    std::swap(client_ip_, other->client_ip_);
    std::swap(client_port_, other->client_port_);
    std::swap(seq_num_, other->seq_num_);
    std::swap(opcode_, other->opcode_);
    std::swap(key_, other->key_);
    std::swap(val_, other->val_);
    std::swap(newval_, other->newval_);
    std::swap(lease_, other->lease_);
    std::swap(valnull_, other->valnull_);
    std::swap(newvalnull_, other->newvalnull_);
    std::swap(replicanum_, other->replicanum_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ZPack::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ZPack_descriptor_;
  metadata.reflection = ZPack_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
