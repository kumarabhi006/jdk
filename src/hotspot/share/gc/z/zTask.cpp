/*
 * Copyright (c) 2017, 2025, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#include "gc/z/zTask.hpp"

ZTask::Task::Task(ZTask* task, const char* name)
  : WorkerTask(name),
    _task(task) {}

void ZTask::Task::work(uint worker_id) {
  _task->work();
}

ZTask::ZTask(const char* name)
  : _worker_task(this, name) {}

const char* ZTask::name() const {
  return _worker_task.name();
}

WorkerTask* ZTask::worker_task() {
  return &_worker_task;
}

ZRestartableTask::ZRestartableTask(const char* name)
  : ZTask(name) {}

void ZRestartableTask::resize_workers(uint nworkers) {}
