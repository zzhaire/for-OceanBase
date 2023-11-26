#pragma once

#include <string>
#include <vector>

#include "sql/expr/expression.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"

class DropTableStmt : public Stmt
{
public:
  DropTableStmt(const std::string &table_name) : relation_name(table_name) {}
  virtual ~DropTableStmt() = default;
  StmtType           type() const override { return StmtType::DROP_TABLE; }
  const std::string &table_name() const { return relation_name; }
  static RC          create(Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt);

private:
  std::string relation_name;
};