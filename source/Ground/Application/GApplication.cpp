/*Ground Engine (https://www.pardcode.com/groundengine)

Copyright (c) 2021, PardCode All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#include <Ground/Application/GApplication.h>
#include <stdexcept>
#include <assert.h>
using namespace ground;


GApplication* GApplication::m_instance = nullptr;


ground::GApplication::GApplication()
{
	GASSERT(!m_instance);
	m_instance = this;
	m_engine = ground::CreateGroundEngine();
}

ground::GApplication::~GApplication()
{
	m_engine->release();
}

void ground::GApplication::run()
{
	onInit();

	while (m_isRunning)
	{
		onUpdate();
	}

	onQuit();
}

void ground::GApplication::quit()
{
	m_isRunning = false;
}

GApplication* ground::GApplication::get()
{
	GASSERT(m_instance);
	return m_instance;
}
