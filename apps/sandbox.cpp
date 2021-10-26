#include <iostream>

#include <sql_query/query_collector.hpp>

int main() {
    QueryCollector qc;
    
    qc.push_sql("SELECT");
    std::cout << "push_sql(): " << qc.query() << '\n';
    qc.reset();

    qc.push_identifier("table.col\"umn\"");
    std::cout << "push_identifier(): " << qc.query() << '\n';
    qc.reset();

    qc.push_bind_param("78");
    auto [query, binds] = qc.finish();
    std::cout << "push_bind_param(): " << query << ", binds[0] = " << binds[0] << '\n';
}

