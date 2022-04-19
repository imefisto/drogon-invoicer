#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

namespace v1
{
namespace invoices
{
class list : public drogon::HttpSimpleController<list>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/v1/invoices", Get);
    PATH_LIST_END
};
}
}
