#ifndef LLARP_HANDLERS_NULL_HPP
#define LLARP_HANDLERS_NULL_HPP

#include <service/endpoint.hpp>

namespace llarp
{
  namespace handlers
  {
    struct NullEndpoint final : public llarp::service::Endpoint
    {
      NullEndpoint(const std::string &name, llarp::Router *r)
          : llarp::service::Endpoint(name, r){};

      bool HandleWriteIPPacket(llarp_buffer_t,
                               std::function< huint32_t(void) >) override
      {
        return true;
      }

      huint32_t
      ObtainIPForAddr(const byte_t *, bool) override
      {
        return {0};
      }

      bool
      HasAddress(const byte_t *) const override
      {
        return false;
      }
    };
  }  // namespace handlers
}  // namespace llarp

#endif
