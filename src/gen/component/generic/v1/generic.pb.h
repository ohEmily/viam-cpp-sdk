// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: component/generic/v1/generic.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_component_2fgeneric_2fv1_2fgeneric_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_component_2fgeneric_2fv1_2fgeneric_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "google/api/annotations.pb.h"
#include <google/protobuf/struct.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_component_2fgeneric_2fv1_2fgeneric_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_component_2fgeneric_2fv1_2fgeneric_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_component_2fgeneric_2fv1_2fgeneric_2eproto;
namespace viam {
namespace component {
namespace generic {
namespace v1 {
class DoCommandRequest;
struct DoCommandRequestDefaultTypeInternal;
extern DoCommandRequestDefaultTypeInternal _DoCommandRequest_default_instance_;
class DoCommandResponse;
struct DoCommandResponseDefaultTypeInternal;
extern DoCommandResponseDefaultTypeInternal _DoCommandResponse_default_instance_;
}  // namespace v1
}  // namespace generic
}  // namespace component
}  // namespace viam
PROTOBUF_NAMESPACE_OPEN
template<> ::viam::component::generic::v1::DoCommandRequest* Arena::CreateMaybeMessage<::viam::component::generic::v1::DoCommandRequest>(Arena*);
template<> ::viam::component::generic::v1::DoCommandResponse* Arena::CreateMaybeMessage<::viam::component::generic::v1::DoCommandResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace viam {
namespace component {
namespace generic {
namespace v1 {

// ===================================================================

class DoCommandRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:viam.component.generic.v1.DoCommandRequest) */ {
 public:
  inline DoCommandRequest() : DoCommandRequest(nullptr) {}
  ~DoCommandRequest() override;
  explicit PROTOBUF_CONSTEXPR DoCommandRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DoCommandRequest(const DoCommandRequest& from);
  DoCommandRequest(DoCommandRequest&& from) noexcept
    : DoCommandRequest() {
    *this = ::std::move(from);
  }

  inline DoCommandRequest& operator=(const DoCommandRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline DoCommandRequest& operator=(DoCommandRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DoCommandRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const DoCommandRequest* internal_default_instance() {
    return reinterpret_cast<const DoCommandRequest*>(
               &_DoCommandRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DoCommandRequest& a, DoCommandRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(DoCommandRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DoCommandRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  DoCommandRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<DoCommandRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DoCommandRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const DoCommandRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DoCommandRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "viam.component.generic.v1.DoCommandRequest";
  }
  protected:
  explicit DoCommandRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kCommandFieldNumber = 2,
  };
  // string name = 1 [json_name = "name"];
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .google.protobuf.Struct command = 2 [json_name = "command"];
  bool has_command() const;
  private:
  bool _internal_has_command() const;
  public:
  void clear_command();
  const ::PROTOBUF_NAMESPACE_ID::Struct& command() const;
  PROTOBUF_NODISCARD ::PROTOBUF_NAMESPACE_ID::Struct* release_command();
  ::PROTOBUF_NAMESPACE_ID::Struct* mutable_command();
  void set_allocated_command(::PROTOBUF_NAMESPACE_ID::Struct* command);
  private:
  const ::PROTOBUF_NAMESPACE_ID::Struct& _internal_command() const;
  ::PROTOBUF_NAMESPACE_ID::Struct* _internal_mutable_command();
  public:
  void unsafe_arena_set_allocated_command(
      ::PROTOBUF_NAMESPACE_ID::Struct* command);
  ::PROTOBUF_NAMESPACE_ID::Struct* unsafe_arena_release_command();

  // @@protoc_insertion_point(class_scope:viam.component.generic.v1.DoCommandRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::Struct* command_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_component_2fgeneric_2fv1_2fgeneric_2eproto;
};
// -------------------------------------------------------------------

class DoCommandResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:viam.component.generic.v1.DoCommandResponse) */ {
 public:
  inline DoCommandResponse() : DoCommandResponse(nullptr) {}
  ~DoCommandResponse() override;
  explicit PROTOBUF_CONSTEXPR DoCommandResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DoCommandResponse(const DoCommandResponse& from);
  DoCommandResponse(DoCommandResponse&& from) noexcept
    : DoCommandResponse() {
    *this = ::std::move(from);
  }

  inline DoCommandResponse& operator=(const DoCommandResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline DoCommandResponse& operator=(DoCommandResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DoCommandResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const DoCommandResponse* internal_default_instance() {
    return reinterpret_cast<const DoCommandResponse*>(
               &_DoCommandResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(DoCommandResponse& a, DoCommandResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(DoCommandResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DoCommandResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  DoCommandResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<DoCommandResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DoCommandResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const DoCommandResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DoCommandResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "viam.component.generic.v1.DoCommandResponse";
  }
  protected:
  explicit DoCommandResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResultFieldNumber = 1,
  };
  // .google.protobuf.Struct result = 1 [json_name = "result"];
  bool has_result() const;
  private:
  bool _internal_has_result() const;
  public:
  void clear_result();
  const ::PROTOBUF_NAMESPACE_ID::Struct& result() const;
  PROTOBUF_NODISCARD ::PROTOBUF_NAMESPACE_ID::Struct* release_result();
  ::PROTOBUF_NAMESPACE_ID::Struct* mutable_result();
  void set_allocated_result(::PROTOBUF_NAMESPACE_ID::Struct* result);
  private:
  const ::PROTOBUF_NAMESPACE_ID::Struct& _internal_result() const;
  ::PROTOBUF_NAMESPACE_ID::Struct* _internal_mutable_result();
  public:
  void unsafe_arena_set_allocated_result(
      ::PROTOBUF_NAMESPACE_ID::Struct* result);
  ::PROTOBUF_NAMESPACE_ID::Struct* unsafe_arena_release_result();

  // @@protoc_insertion_point(class_scope:viam.component.generic.v1.DoCommandResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::Struct* result_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_component_2fgeneric_2fv1_2fgeneric_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DoCommandRequest

// string name = 1 [json_name = "name"];
inline void DoCommandRequest::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& DoCommandRequest::name() const {
  // @@protoc_insertion_point(field_get:viam.component.generic.v1.DoCommandRequest.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DoCommandRequest::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:viam.component.generic.v1.DoCommandRequest.name)
}
inline std::string* DoCommandRequest::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:viam.component.generic.v1.DoCommandRequest.name)
  return _s;
}
inline const std::string& DoCommandRequest::_internal_name() const {
  return name_.Get();
}
inline void DoCommandRequest::_internal_set_name(const std::string& value) {
  
  name_.Set(value, GetArenaForAllocation());
}
inline std::string* DoCommandRequest::_internal_mutable_name() {
  
  return name_.Mutable(GetArenaForAllocation());
}
inline std::string* DoCommandRequest::release_name() {
  // @@protoc_insertion_point(field_release:viam.component.generic.v1.DoCommandRequest.name)
  return name_.Release();
}
inline void DoCommandRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault()) {
    name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:viam.component.generic.v1.DoCommandRequest.name)
}

// .google.protobuf.Struct command = 2 [json_name = "command"];
inline bool DoCommandRequest::_internal_has_command() const {
  return this != internal_default_instance() && command_ != nullptr;
}
inline bool DoCommandRequest::has_command() const {
  return _internal_has_command();
}
inline const ::PROTOBUF_NAMESPACE_ID::Struct& DoCommandRequest::_internal_command() const {
  const ::PROTOBUF_NAMESPACE_ID::Struct* p = command_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Struct&>(
      ::PROTOBUF_NAMESPACE_ID::_Struct_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Struct& DoCommandRequest::command() const {
  // @@protoc_insertion_point(field_get:viam.component.generic.v1.DoCommandRequest.command)
  return _internal_command();
}
inline void DoCommandRequest::unsafe_arena_set_allocated_command(
    ::PROTOBUF_NAMESPACE_ID::Struct* command) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(command_);
  }
  command_ = command;
  if (command) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:viam.component.generic.v1.DoCommandRequest.command)
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandRequest::release_command() {
  
  ::PROTOBUF_NAMESPACE_ID::Struct* temp = command_;
  command_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandRequest::unsafe_arena_release_command() {
  // @@protoc_insertion_point(field_release:viam.component.generic.v1.DoCommandRequest.command)
  
  ::PROTOBUF_NAMESPACE_ID::Struct* temp = command_;
  command_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandRequest::_internal_mutable_command() {
  
  if (command_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Struct>(GetArenaForAllocation());
    command_ = p;
  }
  return command_;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandRequest::mutable_command() {
  ::PROTOBUF_NAMESPACE_ID::Struct* _msg = _internal_mutable_command();
  // @@protoc_insertion_point(field_mutable:viam.component.generic.v1.DoCommandRequest.command)
  return _msg;
}
inline void DoCommandRequest::set_allocated_command(::PROTOBUF_NAMESPACE_ID::Struct* command) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(command_);
  }
  if (command) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(command));
    if (message_arena != submessage_arena) {
      command = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, command, submessage_arena);
    }
    
  } else {
    
  }
  command_ = command;
  // @@protoc_insertion_point(field_set_allocated:viam.component.generic.v1.DoCommandRequest.command)
}

// -------------------------------------------------------------------

// DoCommandResponse

// .google.protobuf.Struct result = 1 [json_name = "result"];
inline bool DoCommandResponse::_internal_has_result() const {
  return this != internal_default_instance() && result_ != nullptr;
}
inline bool DoCommandResponse::has_result() const {
  return _internal_has_result();
}
inline const ::PROTOBUF_NAMESPACE_ID::Struct& DoCommandResponse::_internal_result() const {
  const ::PROTOBUF_NAMESPACE_ID::Struct* p = result_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Struct&>(
      ::PROTOBUF_NAMESPACE_ID::_Struct_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Struct& DoCommandResponse::result() const {
  // @@protoc_insertion_point(field_get:viam.component.generic.v1.DoCommandResponse.result)
  return _internal_result();
}
inline void DoCommandResponse::unsafe_arena_set_allocated_result(
    ::PROTOBUF_NAMESPACE_ID::Struct* result) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(result_);
  }
  result_ = result;
  if (result) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:viam.component.generic.v1.DoCommandResponse.result)
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandResponse::release_result() {
  
  ::PROTOBUF_NAMESPACE_ID::Struct* temp = result_;
  result_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandResponse::unsafe_arena_release_result() {
  // @@protoc_insertion_point(field_release:viam.component.generic.v1.DoCommandResponse.result)
  
  ::PROTOBUF_NAMESPACE_ID::Struct* temp = result_;
  result_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandResponse::_internal_mutable_result() {
  
  if (result_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Struct>(GetArenaForAllocation());
    result_ = p;
  }
  return result_;
}
inline ::PROTOBUF_NAMESPACE_ID::Struct* DoCommandResponse::mutable_result() {
  ::PROTOBUF_NAMESPACE_ID::Struct* _msg = _internal_mutable_result();
  // @@protoc_insertion_point(field_mutable:viam.component.generic.v1.DoCommandResponse.result)
  return _msg;
}
inline void DoCommandResponse::set_allocated_result(::PROTOBUF_NAMESPACE_ID::Struct* result) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(result_);
  }
  if (result) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(result));
    if (message_arena != submessage_arena) {
      result = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
    }
    
  } else {
    
  }
  result_ = result;
  // @@protoc_insertion_point(field_set_allocated:viam.component.generic.v1.DoCommandResponse.result)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace generic
}  // namespace component
}  // namespace viam

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_component_2fgeneric_2fv1_2fgeneric_2eproto
