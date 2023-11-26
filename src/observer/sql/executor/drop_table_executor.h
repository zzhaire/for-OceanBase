#pragma once

#include "common/rc.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "sql/executor/sql_result.h"
#include "sql/operator/string_list_physical_operator.h"
#include "sql/stmt/drop_table_stmt.h"
#include "session/session.h"

class DropTableExecutor
{
public:
  DropTableExecutor()          = default;
  virtual ~DropTableExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};