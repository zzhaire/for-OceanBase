#include "sql/executor/execute_stage.h"

#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "sql/executor/command_executor.h"
#include "sql/operator/calc_physical_operator.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"
#include "storage/default/default_handler.h"
#include "sql/executor/drop_table_executor.h"

RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt    *stmt    = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::CREATE_TABLE,
            "create table executor can not run this command: %d", static_cast<int>(stmt->type()));

  DropTableStmt *drop_table_stmt = static_cast<DropTableStmt *>(stmt);
  const char    *relation_name   = drop_table_stmt->table_name().c_str();
  RC             rc              = session->get_current_db()->drop_table(relation_name);

  return rc;
};