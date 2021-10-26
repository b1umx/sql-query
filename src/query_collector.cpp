#include <sql_query/query_collector.hpp>


void QueryCollector::push_sql(std::string value) {
    _query += value;
}

void QueryCollector::push_identifier(std::string value) {
    _query += "\"";
    _query += replace_all(value, "\"", "\"\"");
    _query += "\"";
}

void QueryCollector::push_bind_param(std::string value) {
    auto n = _bind_params.size() + 1;
    auto n_str = std::to_string(n);
    _bind_params.push_back(value);
    _query += "$";
    _query += n_str;
}

std::string QueryCollector::query() const {
    return _query;
}

std::pair<std::string, BindParams> QueryCollector::finish() {
    return std::make_pair(std::move(_query), std::move(_bind_params));
}

void QueryCollector::reset() {
    _query.clear();
    _bind_params.clear();
}

std::string QueryCollector::replace_all(const std::string& source, const std::string& from, const std::string& to) {
    std::string target(source);
    
    if (!target.empty()) {
        auto from_size = from.size();
        auto to_size = to.size();

        std::string::size_type pos = 0;
        while ((pos = target.find(from, pos)) != std::string::npos) {
            target.replace(pos, from_size, to);
            pos += to_size;
        }
    }

    return target;
}

