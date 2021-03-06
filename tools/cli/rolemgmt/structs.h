/*
 * Copyright © 2016-2017 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */


#pragma once

typedef enum _ROLEMGMT_OPERATION
{
    ROLEMGMT_OPERATION_LIST   = 0x1,
    ROLEMGMT_OPERATION_SET    = 0x2,
    ROLEMGMT_OPERATION_DELETE = 0x4
}ROLEMGMT_OPERATION;

typedef struct _ROLEMGMT_CMD_ARGS_
{
    int nShowHelp;
    int nShowVersion;
    int nCmdCount;
    ROLEMGMT_OPERATION nOperation;
    char *pszRole;
    char **ppszCmds;
}ROLEMGMT_CMD_ARGS, *PROLEMGMT_CMD_ARGS; 

typedef uint32_t (*PFN_ROLEMGMT_CMD)(PPMDHANDLE, PROLEMGMT_CMD_ARGS);

typedef struct _ROLEMGMT_CLI_CMD_MAP
{
    char* pszCmdName;
    PFN_ROLEMGMT_CMD pFnCmd;
}ROLEMGMT_CLI_CMD_MAP, *PROLEMGMT_CLI_CMD_MAP;
