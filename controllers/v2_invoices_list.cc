#include "v2_invoices_list.h"

using namespace v2::invoices;

void list::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto clientPtr = drogon::app().getDbClient();
    std::string sql = R"(SELECT i.invoice_number, c.name, i.total
    FROM invoices i
    INNER JOIN customers c ON c.id = i.customer_id)";

    auto query = clientPtr->execSqlAsyncFuture(sql);
    auto result = query.get();
    Json::Value invoices(Json::arrayValue);
    Json::Value invoice(Json::objectValue);
    for (auto row : result) {
        invoice["number"] = row["invoice_number"].as<std::string>();
        invoice["customer"] = row["name"].as<std::string>();
        invoice["total"] = row["total"].as<std::string>();
        invoices.append(invoice);
    }

    auto resp=HttpResponse::newHttpJsonResponse(invoices);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_APPLICATION_JSON);
    callback(resp);
}
