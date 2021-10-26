#pragma once

#include <iostream>
#include <vector>


using BindParams = std::vector<std::string>;

class QueryCollector {
public:
    void push_sql(std::string value);
    void push_identifier(std::string value);
    void push_bind_param(std::string value);

    std::string query() const;
    std::pair<std::string, BindParams> finish();
    void reset();

private:
    static std::string replace_all(const std::string& source, const std::string& from, const std::string& to);

private:
    std::string _query;
    BindParams _bind_params;
};

