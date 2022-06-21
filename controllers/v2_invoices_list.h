#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

namespace v2
{
namespace invoices
{
class list : public drogon::HttpSimpleController<list>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/v2/invoices", Get);
    PATH_LIST_END
};
}
}
