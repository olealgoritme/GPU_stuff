﻿#pragma once
#include "headers.h"

class AppData
{
private:
  std::vector<BYTE> bufferSubset;
  RetrieveStruct* retriever;
  Buffer *buffer;
  std::vector<WORD> supportedDeviceIDs = {0x67DF, 0x1002};

  int atom_vram_info_offset;
  int atom_sclk_table_offset;
  int AtomPowertuneOffset;
  int AtomFanTableOffset;
  int AtomSysClockEntriesOffset;
  int AtomMemClockTableOffset;
  int atomVoltageTableOffset;
  int AtomVramEntryOffset;
  int AtomVramTimingOffset;

  ATOM_ROM_HEADER atom_rom_header;
  ATOM_DATA_TABLES atom_data_table;
  ATOM_POWERPLAY_TABLE atom_powerplay_table;
  ATOM_POWERTUNE_TABLE atom_powertune_table;
  ATOM_FAN_TABLE atom_fan_table;
  ATOM_SCLK_TABLE atom_sclk_table;
  std::vector<ATOM_SCLK_ENTRY> atom_sclk_entries;
  ATOM_MCLK_TABLE atom_mclk_table;
  std::vector<ATOM_MCLK_ENTRY> atom_mclk_entries;
  ATOM_VOLTAGE_TABLE atom_vddc_table;
  std::vector<ATOM_VOLTAGE_ENTRY> atom_vddc_entries;
  ATOM_VRAM_INFO atom_vram_info;
  std::vector<ATOM_VRAM_ENTRY> atom_vram_entries;
  std::vector<ATOM_VRAM_TIMING_ENTRY> atom_vram_timing_entries;

  bool setValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency = false);
  void printFileSizeWarning(int fileSize);
  void printFileDetails(const char* filename, Buffer* buffer);
  void validateDeviceId(std::vector<WORD> supportedDeviceIDs, WORD deviceId);
  void getTables();
  void getBootstrapTables();
  void getPowertuneTable();
  void getFanTable();
  void getSysClockEntries();
  void getMemClockEntries();
  void getVoltageEntries();
  void getVramInfo();
  void getVramTimingEntries();
  void getVramEntries();

public:
  void OpenFile(std::string Filename);
  void PrintSummary(std::string ReadArea);
  void PrintVerbose(std::string ReadArea);
  void SetTimingStraps(BYTE* InsertData, std::vector<int> To);
  void SetTimingStraps(std::string InsertData, std::vector<int> To);
  void SetTimingStraps(int From, std::vector<int> To);
  void WriteTimingStrapsToBuffer();
  void WriteBufferToFile(std::string FileName);
};
