/*!
 * DZTimer nanobind module file
 *
 * @author Qingwen Zhang (qingwen@kth.se)
 * @version 1.0.0
 * @date 2023-10-21 11:34
 *
 * @copyright Copyright (c) 2022, Qingwen Zhang, KTH Royal Institute of Technology
 *
 * BSD 3-Clause License
 *
 * Copyright (c) 2022, Qingwen Zhang, KTH Royal Institute of Technology
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "timer.hpp"
#include "nanobind/nanobind.h"
#include <nanobind/stl/string.h>

NB_MODULE(dztimer, m) {
    nanobind::class_<Timer>(m, "Timer")
        .def("start", static_cast<void (Timer::*)()>(&Timer::start))
        .def("stop", &Timer::stop);

    nanobind::class_<Timing, Timer>(m, "Timing")
        .def(nanobind::init<>())
        .def(nanobind::init<const std::string &>())
        .def("start", static_cast<void (Timing::*)(const std::string &)>(&Timing::start))
        .def("start", static_cast<void (Timing::*)(const std::string &, const std::string &)>(&Timing::start))
        .def("__getitem__", static_cast<Timing& (Timing::*)(std::size_t)>(&Timing::operator[]), nanobind::rv_policy::reference)
        .def("print", &Timing::print, nanobind::arg("title")="Default", nanobind::arg("random_colors")=false, nanobind::arg("bold")=false, 
             nanobind::arg("group_colors_level")=std::numeric_limits<std::size_t>::max(), nanobind::arg("precision")=4);
}