#include <fstream>
#include "v1_invoices_list.h"

using namespace v1::invoices;

void list::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    Json::Value invoice1(Json::objectValue);
    invoice1["id"] = "1";
    invoice1["customer"] = "Antonio D. Bain";
    invoice1["total"] = 10.50;

    Json::Value invoice2(Json::objectValue);
    invoice2["id"] = "2";
    invoice2["customer"] = "Grace R. Shaw";
    invoice2["total"] = 34.54;

    Json::Value invoices(Json::arrayValue);
    invoices.append(invoice1);
    invoices.append(invoice2);

    auto resp=HttpResponse::newHttpJsonResponse(invoices);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_APPLICATION_JSON);
    callback(resp);
}
