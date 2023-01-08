#include <iostream>
#include <cinttypes>
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include "include/capstone/capstone.h"

#pragma comment(lib, "capstone.lib")

using namespace std;

int main(void)
{
    HMODULE NTDLLBase = GetModuleHandle(_T("ntdll.dll"));
    if (NTDLLBase == NULL) {
        _tprintf(_T("[x] Failed to get ntdll.dll module\n"));
        return 0;
    }

    // ��ȡntdll��.text�ε�ַ���Լ�.text�δ�С
    PUCHAR NTDLLCode = (PUCHAR)((UINT_PTR)NTDLLBase + 0x1000);
    PIMAGE_NT_HEADERS NTDLLPEHeader = (PIMAGE_NT_HEADERS)((UINT_PTR)NTDLLBase + ((IMAGE_DOS_HEADER*)NTDLLBase)->e_lfanew);
    DWORD NTDLLCodeSize = NTDLLPEHeader->OptionalHeader.SizeOfCode;

    csh handle;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle)) {
        printf("ERROR: Failed to initialize engine!\n");
        return -1;
    }

    cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);

    const int MAX_OPCODE_SIZE = 16; // OPָ�����󳤶�
    const int MAX_OPCODE_COUNT = 5; // һ���Է���������
    for (unsigned int i = 0; i < NTDLLCodeSize - MAX_OPCODE_SIZE * MAX_OPCODE_COUNT; i++) {

        // һ���Է���� MAX_OPCODE_COUNT ��ָ��
        cs_insn* insn;
        size_t count = cs_disasm(handle, NTDLLCode + i, MAX_OPCODE_SIZE * MAX_OPCODE_COUNT, 0, MAX_OPCODE_COUNT, &insn);
        if (count == 0)
            continue;

        // Ѱ��movָ��
        if (strcmp(insn->mnemonic, "mov") != 0) {
            cs_free(insn, count);
            continue;
        }

        cs_x86_op* opl = &(insn->detail->x86.operands[0]);
        cs_x86_op* opr = &(insn->detail->x86.operands[1]);

        // Ҫ���������Ϊ�ڴ棬�Ҳ�����Ϊ�Ĵ���
        if (opl->type != X86_OP_MEM || opr->type != X86_OP_REG) {
            cs_free(insn, count);
            continue;
        }

        // ����Ҳ����Ƿ�Ϊ���������Ĵ���
        if (opr->reg != X86_REG_RBX &&
            opr->reg != X86_REG_RSI &&
            opr->reg != X86_REG_RDI &&
            opr->reg != X86_REG_R12 &&
            opr->reg != X86_REG_R13 &&
            opr->reg != X86_REG_R14 &&
            opr->reg != X86_REG_R15) {
            cs_free(insn, count);
            continue;
        }

        // �����������Ƿ�Ϊ���������Ĵ���
        if (opl->mem.base != X86_REG_RBX &&
            opl->mem.base != X86_REG_RSI &&
            opl->mem.base != X86_REG_RDI &&
            opl->mem.base != X86_REG_R12 &&
            opl->mem.base != X86_REG_R13 &&
            opl->mem.base != X86_REG_R14 &&
            opl->mem.base != X86_REG_R15) {
            cs_free(insn, count);
            continue;
        }

        // �����������Ƿ����λ����
        //if (opl->mem.disp != 0) {
        //    cs_free(insn, count);
        //    continue;
        //}

        // ��������Ƿ�����Ҳ�����
        if (opl->mem.base == opr->reg) {
            cs_free(insn, count);
            continue;
        }

        // Ѱ�ҷ���������retָ��
        for (size_t j = 1; j < count; j++) {

            // Ѱ�� ret ָ��
            if (strcmp(insn[j].mnemonic, "ret") == 0) {

                for (size_t k = 0; k <= j; k++) {
                    printf("0x%Ix:\t%s\t\t%s\n", 0x180001000 + i, insn[k].mnemonic, insn[k].op_str);
                }
                printf("\n");
                break;
            }

            // ���� mov reg, ?? ָ��
            else if (strcmp(insn[j].mnemonic, "mov") == 0) {

                cs_x86_op* opl = &(insn[j].detail->x86.operands[0]);

                // Ҫ���������Ϊ�Ĵ���
                if (opl->type != X86_OP_REG) {
                    break;
                }
            }

            // ���� add rsp, ?? ָ��
            else if (strcmp(insn[j].mnemonic, "add") == 0) {

                cs_x86_op* opl = &(insn[j].detail->x86.operands[0]);
                cs_x86_op* opr = &(insn[j].detail->x86.operands[1]);

                // Ҫ���������Ϊ�Ĵ������Ҳ�����Ϊ������
                if (opl->type != X86_OP_REG || opr->type != X86_OP_IMM) {
                    break;
                }

                //printf("0x%Ix:\t%s\t\t%s\n", 0x180001000 + i, insn[j].mnemonic, insn[j].op_str);
                //printf("insn->detail->x86.op_count = %d, opl->type = %d, opr->type = %d\n", insn->detail->x86.op_count, opl->type, opr->type);

                // ������������rsp���򱣴�������
                if (opl->reg == X86_REG_RSP) {
                    // opr->imm
                }
            }

            // ���� xor reg, ?? ָ��
            else if (strcmp(insn[j].mnemonic, "xor") == 0) {

                cs_x86_op* opl = &(insn[j].detail->x86.operands[0]);

                // Ҫ���������Ϊ�Ĵ���
                if (opl->type != X86_OP_REG) {
                    break;
                }
            }

            // ���� pop reg ָ��
            else if (strcmp(insn[j].mnemonic, "pop") == 0) {

                // ����pop����
            }

            // ����������ָ��
            else {
                break;
            }
        }

        cs_free(insn, count);
        
    }

    cs_close(&handle);

    return 0;
}
