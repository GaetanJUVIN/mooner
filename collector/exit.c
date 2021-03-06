/*
**    objectivemoon.io stage1 feeler
**    Copyright (C) 2014 Kwame
**
**    This program is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <unistd.h>
#include "moon.h"
#include "mooner.h"

/*
**
*/
void			mooner_exit(int status)
{
  int			ret;

  ret=unlink(e->pidfile_path);
  if (ret < 0 && !(e->option & OPT_GARBAGE))
    send_log(LOG_NOTICE, "[13] can't unlink file [%s]\n",e->pidfile_path);
  close_log_file();
  free(e->msg_tab);
  free_rmq_server_list();
  free(e->filter);
  free(e->myhostname);
  free(e);
  exit(status);
}
