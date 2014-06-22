bool isFindXtml;
HANDLE Skin_hMapFile;
HANDLE Skin_hFile;
BYTE* Skin_buffer;
int Skin_length;


void ChageSoso(int soso_Offset1,int soso_Offset2)
{
	int state = GetPrivateProfileInt(L"�������",L"Com.Tencent.Soso", -1, tzIniPath);
	if(state==-1)
	{
		state = GetPrivateProfileInt(L"�������",L"Com.Tencent.Soso", 0, tzUACPath);
	}

	if(state==0)
	{
		Skin_buffer[soso_Offset1] = 0x4B;
		Skin_buffer[soso_Offset2] = 0xF7;
	}
}
void SkinsPatch(BYTE* buffer)
{
	Skin_buffer = buffer;
	int len = Skin_length;
	//DbgPrint(L"%X",len);
	//
	//
	BYTE key1[] = {0x09, 0x1C, 0x00, 0x80, 0xE3, 0x8F, 0xE3, 0x8A, 0xE3, 0x86, 0xE3, 0x8D, 0xE3, 0x97, 0xE3, 0xA2, 0xE3, 0x91, 0xE3, 0x86, 0xE3, 0x82, 0xE3, 0xB0, 0xE3, 0x8A, 0xE3, 0x99, 0xE3, 0x86, 0xE3, 0x08, 0x00, 0x00, 0x00, 0xF8, 0xF5, 0xF7, 0xF7, 0xEA, 0xF6, 0xF7, 0xF7};
	long FingerFrame1 = memstr(key1,sizeof(key1),buffer,len);
	if(FingerFrame1!=-1)
	{
	 	//DbgPrint(L"FingerFrame1");
		buffer[FingerFrame1+35] = 0x7D;
		buffer[FingerFrame1+36] = 0xF6;
		
		BYTE key2[] = {0x07, 0x10, 0x00, 0x89, 0xEF, 0x86, 0xEF, 0x83, 0xEF, 0x83, 0xEF, 0xA6, 0xEF, 0x9B, 0xEF, 0x8A, 0xEF, 0x82, 0xEF, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
		int offset = FingerFrame1 + sizeof(key1);
		long FingerFrame2 = memstr(key2,sizeof(key2),buffer + offset,0x1000);
		if(FingerFrame2!=-1)
		{
			buffer[offset+FingerFrame2+23] = 0x00;
			//DbgPrint(L"%X %X",FingerFrame2,offset+FingerFrame2+23);
		}
		
	}

	BYTE key3[] = {0x08, 0x0C, 0x00, 0x90, 0xF3, 0x9C, 0xF3, 0x9D, 0xF3, 0x95, 0xF3, 0x9A, 0xF3, 0x94, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x93, 0xDF, 0xB0, 0xDF, 0xBC, 0xDF, 0xB4, 0xDF, 0x8F, 0xDF, 0xBE, 0xDF, 0xB1, 0xDF, 0xBA, 0xDF, 0xB3, 0xDF, 0x80, 0xDF, 0xA8, 0xDF, 0xB6, 0xDF, 0xB1, 0xDF, 0xBB, 0xDF, 0xB0, 0xDF, 0xA8, 0xDF, 0x09, 0x1C, 0x00, 0x80, 0xE3, 0x8F, 0xE3, 0x8A, 0xE3, 0x86, 0xE3, 0x8D, 0xE3, 0x97, 0xE3, 0xA2, 0xE3, 0x91, 0xE3, 0x86, 0xE3, 0x82, 0xE3, 0xB0, 0xE3, 0x8A, 0xE3, 0x99, 0xE3, 0x86, 0xE3, 0x08, 0x00, 0x00, 0x00, 0xDD, 0xF6, 0xF7, 0xF7, 0xC9, 0xF5, 0xF7, 0xF7, 0x09, 0x0E, 0x00, 0x9C, 0xF1, 0x98, 0xF1, 0x9F, 0xF1, 0xA2, 0xF1, 0x98, 0xF1, 0x8B, 0xF1, 0x94, 0xF1, 0x08, 0x00, 0x00, 0x00, 0xDE, 0xF6, 0xF7, 0xF7, 0x80, 0xF6};
	long lockpanel = memstr(key3,sizeof(key3),buffer,len);
	if(lockpanel!=-1)
	{
	 	//DbgPrint(L"lockpanel");
		//DbgPrint(L"%X %X",lockpanel,buffer[lockpanel+35+51]);
		buffer[lockpanel+35+51] = 0x0D;
		buffer[lockpanel+36+51] = 0xF7;
		buffer[lockpanel+64+51] = 0x0D;
		buffer[lockpanel+65+51] = 0xF7;
		//DbgPrint(L"%X %X",lockpanel,buffer[lockpanel+64]);
	}
	BYTE key4[] = {0x08, 0x0C, 0x00, 0x90, 0xF3, 0x9C, 0xF3, 0x9D, 0xF3, 0x95, 0xF3, 0x9A, 0xF3, 0x94, 0xF3, 0x28, 0x00, 0x00, 0x00, 0x84, 0xD7, 0xA3, 0xD7, 0xB3, 0xD7, 0x9B, 0xD7, 0xB8, 0xD7, 0xB0, 0xD7, 0xBE, 0xD7, 0xB9, 0xD7, 0x87, 0xD7, 0xB6, 0xD7, 0xB9, 0xD7, 0xB2, 0xD7, 0xBB, 0xD7, 0x88, 0xD7, 0xA0, 0xD7, 0xBE, 0xD7, 0xB9, 0xD7, 0xB3, 0xD7, 0xB8, 0xD7, 0xA0, 0xD7, 0x09, 0x1C, 0x00, 0x80, 0xE3, 0x8F, 0xE3, 0x8A, 0xE3, 0x86, 0xE3, 0x8D, 0xE3, 0x97, 0xE3, 0xA2, 0xE3, 0x91, 0xE3, 0x86, 0xE3, 0x82, 0xE3, 0xB0, 0xE3, 0x8A, 0xE3, 0x99, 0xE3, 0x86, 0xE3, 0x08, 0x00, 0x00, 0x00, 0xDD, 0xF6, 0xF7, 0xF7, 0xC9, 0xF5, 0xF7, 0xF7, 0x09, 0x0E, 0x00, 0x9C, 0xF1, 0x98, 0xF1, 0x9F, 0xF1, 0xA2, 0xF1, 0x98, 0xF1, 0x8B, 0xF1, 0x94, 0xF1, 0x08, 0x00, 0x00, 0x00, 0xDE, 0xF6, 0xF7, 0xF7, 0x80, 0xF6};
	long StdLoginPanel = memstr(key4,sizeof(key4),buffer,len);
	if(StdLoginPanel!=-1)
	{
	 	//DbgPrint(L"StdLoginPanel");
		//DbgPrint(L"%X %X",StdLoginPanel,buffer[StdLoginPanel+35+59]);
		
		buffer[StdLoginPanel+35+59] = 0x0D;
		buffer[StdLoginPanel+36+59] = 0xF7;
		buffer[StdLoginPanel+64+59] = 0x0D;
		buffer[StdLoginPanel+65+59] = 0xF7;
		
		//DbgPrint(L"%X %X",lockpanel,buffer[lockpanel+64]);
	}

	//QQ2012
	BYTE QQ2012[] = {0x09, 0x0E, 0x00, 0x9C, 0xF1, 0x98, 0xF1, 0x9F, 0xF1, 0xA2, 0xF1, 0x98, 0xF1, 0x8B, 0xF1, 0x94, 0xF1, 0x08, 0x00, 0x00, 0x00, 0xD0, 0xF6, 0xF7, 0xF7, 0xEB, 0xF5, 0xF7, 0xF7};
	long startset = 0;
	for(int i=0;i<3;i++)
	{
		long minSize = memstr(QQ2012,sizeof(QQ2012),buffer + startset,len - startset);
		if(minSize!=-1)
		{
			buffer[minSize+startset+21] = 0x0D;
			buffer[minSize+startset+22] = 0xF7;

			startset += minSize + sizeof(QQ2012);
		}
		else break;
	}

	if(!ShowHelpBtn)
	{	
		BYTE key5[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x14, 0x00, 0x00, 0x00, 0xAC, 0xEB, 0x8E, 0xEB, 0x9F, 0xEB, 0xA3, 0xEB, 0x8E, 0xEB, 0x87, 0xEB, 0x9B, 0xEB, 0xA9, 0xEB, 0x9F, 0xEB, 0x85, 0xEB, 0x08, 0x0C, 0x00, 0x92, 0xF3, 0x9D, 0xF3, 0x90, 0xF3, 0x9B, 0xF3, 0x9C, 0xF3, 0x81, 0xF3, 0x10, 0x00, 0x00, 0x00, 0xBB, 0xEF, 0xA0, 0xEF, 0xBF, 0xEF, 0xBD, 0xEF, 0xA6, 0xEF, 0xA8, 0xEF, 0xA7, 0xEF, 0xBB, 0xEF, 0x09, 0x08, 0x00, 0x84, 0xF7, 0x9E, 0xF7, 0x8D, 0xF7, 0x92, 0xF7, 0x08, 0x00, 0x00, 0x00, 0xE1, 0xF7, 0xF7, 0xF7, 0xE5, 0xF7, 0xF7, 0xF7};
		long GetHelpBtn = memstr(key5,sizeof(key5),buffer,len);
		if(GetHelpBtn!=-1)
		{
		 	//DbgPrint(L"GetHelpBtn");
			//DbgPrint(L"%X %X",GetHelpBtn,buffer[GetHelpBtn+89]);
			buffer[GetHelpBtn+85] = 0xF7;
			buffer[GetHelpBtn+89] = 0xF7;
		}
		BYTE key9[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x28, 0x00, 0x00, 0x00, 0x95, 0xD7, 0xA3, 0xD7, 0xB9, 0xD7, 0x88, 0xD7, 0x94, 0xD7, 0xB8, 0xD7, 0xB9, 0xD7, 0xB1, 0xD7, 0xBE, 0xD7, 0xB0, 0xD7, 0x94, 0xD7, 0xB2, 0xD7, 0xB9, 0xD7, 0xA3, 0xD7, 0xB2, 0xD7, 0xA5, 0xD7, 0x9F, 0xD7, 0xB2, 0xD7, 0xBB, 0xD7, 0xA7, 0xD7, 0x09};
		long Btn_ConfigCenterHelp = memstr(key9,sizeof(key9),buffer,len);
		if(Btn_ConfigCenterHelp!=-1)
		{
			BYTE key10[] = {0x08, 0x00, 0x84, 0xF7, 0x9E, 0xF7, 0x8D, 0xF7, 0x92, 0xF7, 0x08, 0x00, 0x00, 0x00, 0xE1, 0xF7, 0xF7, 0xF7, 0xE5, 0xF7, 0xF7, 0xF7};
			int offset = Btn_ConfigCenterHelp + sizeof(key9);
			Btn_ConfigCenterHelp = memstr(key10,sizeof(key10),buffer+offset,len-offset);
			if(Btn_ConfigCenterHelp!=-1)
			{
				//DbgPrint(L"Btn_ConfigCenterHelp %X",);
				//buffer[Btn_ConfigCenterHelp] = 0x0F;
				buffer[Btn_ConfigCenterHelp+14+offset] = 0xF7;
				buffer[Btn_ConfigCenterHelp+18+offset] = 0xF7;

			}
		}
	}


	BYTE key6[] = {0x08, 0x0C, 0x00, 0x90, 0xF3, 0x9C, 0xF3, 0x9D, 0xF3, 0x95, 0xF3, 0x9A, 0xF3, 0x94, 0xF3, 0x2C, 0x00, 0x00, 0x00, 0xA7, 0xD3, 0xB2, 0xD3, 0xB1, 0xD3, 0xB0, 0xD3, 0xA7, 0xD3, 0xA1, 0xD3, 0xBF, 0xD3, 0x8C, 0xD3, 0xA0, 0xD3, 0xBB, 0xD3, 0xBC, 0xD3, 0xA4, 0xD3, 0xB0, 0xD3, 0xA6, 0xD3, 0xA0, 0xD3, 0xA7, 0xD3, 0xBC, 0xD3, 0xBE, 0xD3, 0xB5, 0xD3, 0xB2, 0xD3, 0xB0, 0xD3, 0xB6, 0xD3, 0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x18, 0x00, 0x00, 0x00, 0x93, 0xE7, 0x86, 0xE7, 0x85, 0xE7, 0xA1, 0xE7, 0x86, 0xE7, 0x84, 0xE7, 0x82, 0xE7, 0xA0, 0xE7, 0x95, 0xE7, 0x88, 0xE7, 0x92, 0xE7, 0x97, 0xE7, 0x09, 0x10, 0x00, 0x83, 0xEF, 0x80, 0xEF, 0x8C, 0xEF, 0x8E, 0xEF, 0x9B, 0xEF, 0x86, 0xEF, 0x80, 0xEF, 0x81, 0xEF, 0x08, 0x00, 0x00, 0x00, 0xF7, 0xF7, 0xF7, 0xF7, 0xF6, 0xF7, 0xF7, 0xF7, 0x09, 0x08, 0x00, 0x84, 0xF7, 0x9E, 0xF7, 0x8D, 0xF7, 0x92, 0xF7, 0x08, 0x00, 0x00, 0x00, 0xE1, 0xF6, 0xF7, 0xF7, 0xE1, 0xF7, 0xF7, 0xF7};
	long tabFaceGroup = memstr(key6,sizeof(key6),buffer,len);
	if(tabFaceGroup!=-1)
	{
	 	//DbgPrint(L"tabFaceGroup");
		BYTE key7[] = {0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x1E, 0x00, 0x00, 0x00, 0xB2, 0xE1, 0x8E, 0xE1, 0xB2, 0xE1, 0x8E, 0xE1, 0xA7, 0xE1, 0x80, 0xE1, 0x82, 0xE1, 0x84, 0xE1, 0xB2, 0xE1, 0x84, 0xE1, 0x80, 0xE1, 0x93, 0xE1, 0xA3, 0xE1, 0x80, 0xE1, 0x93, 0xE1, 0x09, 0x10, 0x00, 0x83, 0xEF, 0x80, 0xEF, 0x8C, 0xEF, 0x8E, 0xEF, 0x9B, 0xEF, 0x86, 0xEF, 0x80, 0xEF, 0x81, 0xEF, 0x08, 0x00, 0x00, 0x00, 0xEF, 0xF6, 0xF7, 0xF7, 0xF6, 0xF7, 0xF7, 0xF7, 0x09, 0x08, 0x00, 0x84, 0xF7, 0x9E, 0xF7, 0x8D, 0xF7, 0x92, 0xF7, 0x08, 0x00, 0x00, 0x00, 0x5F, 0xF7, 0xF7, 0xF7, 0xE0, 0xF7, 0xF7, 0xF7};
		int offset = tabFaceGroup + sizeof(key6);
		long SoSoFaceSearBar = memstr(key7,sizeof(key7),buffer + offset,len-offset);
		if(SoSoFaceSearBar!=-1)
		{
			ChageSoso(tabFaceGroup+148,offset + SoSoFaceSearBar + 90);
		}
	}
	
	if(!ShowFaceBtn)
	{
		BYTE key8[] = {0x08, 0x06, 0x00, 0x90, 0xF9, 0x90, 0xF9, 0x9D, 0xF9, 0x48, 0x00, 0x00, 0x00, 0x87, 0xB7, 0x83, 0xB7, 0x8F, 0xB7, 0x83, 0xB7, 0x8E, 0xB7, 0x80, 0xB7, 0x8F, 0xB7, 0xF5, 0xB7, 0x9A, 0xB7, 0xF3, 0xB7, 0x87, 0xB7, 0x86, 0xB7, 0x87, 0xB7, 0x9A, 0xB7, 0x83, 0xB7, 0xF2, 0xB7, 0xF2, 0xB7, 0x8F, 0xB7, 0x9A, 0xB7, 0xF6, 0xB7, 0xF5, 0xB7, 0xF4, 0xB7, 0x86, 0xB7, 0x9A, 0xB7, 0xF6, 0xB7, 0xF5, 0xB7, 0x87, 0xB7, 0x80, 0xB7, 0xF2, 0xB7, 0x87, 0xB7, 0x84, 0xB7, 0xF3, 0xB7, 0x85, 0xB7, 0x8F, 0xB7, 0x84, 0xB7, 0x82, 0xB7};
		long richface = memstr(key8,sizeof(key8),buffer,len);
		if(richface!=-1)
		{
		 	//DbgPrint(L"richface");
			int offset = richface + sizeof(key8);
			richface = memstr(key8,sizeof(key8),buffer+offset,len-offset);
			if(richface!=-1)
			{
				offset = richface+offset+251;
				//DbgPrint(L"%X",buffer[offset]);
				if(buffer[offset]==0x08) buffer[offset] = 0x0F;
				//DbgPrint(L"%X",buffer[offset]);
			}
		}
	}
	//DbgPrint(L"%X %X,%X %X",soso_Offset1,soso_Offset2,buffer[soso_Offset1],buffer[soso_Offset2]);
	//ChageSoso(0);
	if(!ShowSafeEntry)
	{
		BYTE key[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x1E, 0x00, 0x00, 0x00, 0xAC, 0xE1, 0x80, 0xE1, 0x88, 0xE1, 0x8F, 0xE1, 0xB5, 0xE1, 0x8E, 0xE1, 0x8E, 0xE1, 0x8D, 0xE1, 0xA4, 0xE1, 0x99, 0xE1, 0x95, 0xE1, 0xA0, 0xE1, 0x93, 0xE1, 0x84, 0xE1, 0x80, 0xE1, 0x01, 0x12};
		long MainToolExtArea = memstr(key,sizeof(key),buffer,len);
		if(MainToolExtArea!=-1)
		{
			//DbgPrint(L"%X",buffer[MainToolExtArea]);
			buffer[MainToolExtArea] = 0x0F;
		}

		BYTE key2[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x24, 0x00, 0x00, 0x00, 0x96, 0xDB, 0xBE, 0xDB, 0xB5, 0xDB, 0xAE, 0xDB, 0x84, 0xDB, 0x88, 0xDB, 0xBE, 0xDB, 0xB8, 0xDB, 0xA9, 0xDB, 0xB2, 0xDB, 0xAF, 0xDB, 0xA2, 0xDB, 0x98, 0xDB, 0xBE, 0xDB, 0xB5, 0xDB, 0xAF, 0xDB, 0xBE, 0xDB, 0xA9, 0xDB, 0x08, 0x10};
		long Menu_SecrityCenter = memstr(key2,sizeof(key2),buffer,len);
		if(Menu_SecrityCenter!=-1)
		{
			if(buffer[Menu_SecrityCenter-156]==0x82 && buffer[Menu_SecrityCenter-155]==0xB7)
			{
				buffer[Menu_SecrityCenter-156] = 0x81;
			}
			//buffer[Menu_SecrityCenter-84] = 0x0F;
			//DbgPrint(L"%X",buffer[Menu_SecrityCenter]);
		}
		BYTE key3[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x20, 0x00, 0x00, 0x00, 0x92, 0xDF, 0xBA, 0xDF, 0xB1, 0xDF, 0xAA, 0xDF, 0x80, 0xDF, 0x9E, 0xDF, 0x93, 0xDF, 0x93, 0xDF, 0x8C, 0xDF, 0xBA, 0xDF, 0xAD, 0xDF, 0xA9, 0xDF, 0xB6, 0xDF, 0xBC, 0xDF, 0xBA, 0xDF, 0xAC, 0xDF, 0x08, 0x10};
		long Menu_ALLServices = memstr(key3,sizeof(key3),buffer,len);
		if(Menu_ALLServices!=-1)
		{
			if(buffer[Menu_ALLServices-156+4]==0x82 && buffer[Menu_ALLServices-155+4]==0xB7)
			{
				buffer[Menu_ALLServices-156+4] = 0x81;
			}
		}

	}
	if(!ShowLevelBtn)
	{
		BYTE key1[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x18, 0x00, 0x00, 0x00, 0xB6, 0xE7, 0xB6, 0xE7, 0xAB, 0xE7, 0x82, 0xE7, 0x91, 0xE7, 0x82, 0xE7, 0x8B, 0xE7, 0xA1, 0xE7, 0x95, 0xE7, 0x86, 0xE7, 0x8A, 0xE7, 0x82, 0xE7, 0x09, 0x10, 0x00, 0x83, 0xEF, 0x80, 0xEF, 0x8C, 0xEF, 0x8E, 0xEF, 0x9B, 0xEF, 0x86, 0xEF, 0x80, 0xEF, 0x81, 0xEF, 0x08, 0x00, 0x00, 0x00, 0xBC, 0xF7, 0xF7, 0xF7, 0xF2, 0xF7, 0xF7, 0xF7};
		long QQLevelFrame = memstr(key1,sizeof(key1),buffer,len);
		if(QQLevelFrame!=-1)
		{
			buffer[QQLevelFrame+85] = 0xF7;
			buffer[QQLevelFrame+89] = 0xF7;
			buffer[QQLevelFrame+188] = 0xEF;
		}

		BYTE key2[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x18, 0x00, 0x00, 0x00, 0xB6, 0xE7, 0xB6, 0xE7, 0xAB, 0xE7, 0x82, 0xE7, 0x91, 0xE7, 0x82, 0xE7, 0x8B, 0xE7, 0xB7, 0xE7, 0x86, 0xE7, 0x89, 0xE7, 0x82, 0xE7, 0x8B, 0xE7, 0x0B, 0x14, 0x00, 0x9B, 0xEB, 0x99, 0xEB, 0x84, 0xEB, 0x9B, 0xEB, 0x8E, 0xEB, 0x99, 0xEB, 0x9F, 0xEB, 0x82, 0xEB, 0x8E, 0xEB, 0x98, 0xEB, 0xD9, 0x00, 0x00, 0x00, 0x54, 0x44, 0x01, 0x01, 0x07, 0x00, 0x09, 0x08, 0x00, 0x84, 0xF7, 0x9E, 0xF7, 0x8D, 0xF7, 0x92, 0xF7, 0x08, 0x00, 0x00, 0x00, 0xC5, 0xF7, 0xF7, 0xF7, 0xE1, 0xF7, 0xF7, 0xF7};
		QQLevelFrame = memstr(key2,sizeof(key2),buffer,len);
		if(QQLevelFrame!=-1)
		{
			buffer[QQLevelFrame+87] = 0xF7;
			buffer[QQLevelFrame+91] = 0xF7;
		}
	}

	if(ShowAddBtn)
	{
		BYTE key[] = {0x08, 0x10, 0x00, 0x9D, 0xEF, 0x8A, 0xEF, 0x9F, 0xEF, 0x80, 0xEF, 0x9D, 0xEF, 0x9B, 0xEF, 0xA6, 0xEF, 0x8B, 0xEF, 0x48, 0x00, 0x00, 0x00, 0xD6, 0xB7, 0xD6, 0xB7, 0x8F, 0xB7, 0xD6, 0xB7, 0x83, 0xB7, 0x81, 0xB7, 0xD1, 0xB7, 0x8E, 0xB7, 0x9A, 0xB7, 0x84, 0xB7, 0xD4, 0xB7, 0xD3, 0xB7, 0xD6, 0xB7, 0x9A, 0xB7, 0x83, 0xB7, 0x87, 0xB7, 0x86, 0xB7, 0x84, 0xB7, 0x9A, 0xB7, 0x8F, 0xB7, 0xD4, 0xB7, 0xD2, 0xB7, 0x8F, 0xB7, 0x9A, 0xB7, 0x84, 0xB7, 0xD2, 0xB7, 0xD2, 0xB7, 0x80, 0xB7, 0x80, 0xB7, 0x83, 0xB7, 0xD6, 0xB7, 0x85, 0xB7, 0xD1, 0xB7, 0x81, 0xB7, 0x84, 0xB7, 0x81, 0xB7, 0x08, 0x0C};
		long aio_toobar_add = memstr(key,sizeof(key),buffer,len);
		if(aio_toobar_add!=-1)
		{
			//DbgPrint(L"%X",buffer[aio_toobar_add+95]);
			buffer[aio_toobar_add+95] = 0x0F;
		}

		BYTE key2[] = {0x08, 0x10, 0x00, 0x9D, 0xEF, 0x8A, 0xEF, 0x9F, 0xEF, 0x80, 0xEF, 0x9D, 0xEF, 0x9B, 0xEF, 0xA6, 0xEF, 0x8B, 0xEF, 0x48, 0x00, 0x00, 0x00, 0xF4, 0xB7, 0x84, 0xB7, 0xF1, 0xB7, 0x82, 0xB7, 0x82, 0xB7, 0x81, 0xB7, 0xF2, 0xB7, 0x80, 0xB7, 0x9A, 0xB7, 0x8F, 0xB7, 0x83, 0xB7, 0x82, 0xB7, 0xF1, 0xB7, 0x9A, 0xB7, 0x83, 0xB7, 0xF5, 0xB7, 0xF6, 0xB7, 0x85, 0xB7, 0x9A, 0xB7, 0x8E, 0xB7, 0xF3, 0xB7, 0xF6, 0xB7, 0xF3, 0xB7, 0x9A, 0xB7, 0xF2, 0xB7, 0x8F, 0xB7, 0x83, 0xB7, 0x86, 0xB7, 0xF3, 0xB7, 0x8F, 0xB7, 0x8E, 0xB7, 0xF6, 0xB7, 0xF1, 0xB7, 0x8F, 0xB7, 0xF2, 0xB7, 0xF1, 0xB7, 0x08, 0x0C};
		long aio_toobar_Report = memstr(key2,sizeof(key2),buffer,len);
		if(aio_toobar_Report!=-1)
		{
			//DbgPrint(L"%X",buffer[aio_toobar_Report+95]);
			buffer[aio_toobar_Report+95] = 0x0F;
		}
	}

	if(!ShowUpdateEntry)
	{
		//DbgPrint(L"��������");
		BYTE key[] = {0x08, 0x08, 0x00, 0x99, 0xF7, 0x96, 0xF7, 0x9A, 0xF7, 0x92, 0xF7, 0x1E, 0x00, 0x00, 0x00, 0xAC, 0xE1, 0x84, 0xE1, 0x8F, 0xE1, 0x94, 0xE1, 0xBE, 0xE1, 0xB4, 0xE1, 0x91, 0xE1, 0x85, 0xE1, 0x80, 0xE1, 0x95, 0xE1, 0x84, 0xE1, 0xA9, 0xE1, 0x88, 0xE1, 0x8F, 0xE1, 0x95, 0xE1, 0x08, 0x08, 0x00, 0x83, 0xF7, 0x92, 0xF7, 0x8F, 0xF7, 0x83, 0xF7, 0x3A, 0x00, 0x00, 0x00, 0xE1, 0xC5, 0xB5, 0xC5, 0xA9, 0xC5, 0xA4, 0xC5, 0xB1, 0xC5, 0xA3, 0xC5, 0xAA, 0xC5, 0xB7, 0xC5, 0xA8, 0xC5, 0xFF, 0xC5, 0x88, 0xC5, 0x84, 0xC5, 0x8C, 0xC5, 0x8B, 0xC5, 0x88, 0xC5, 0x80, 0xC5, 0x8B, 0xC5, 0x90, 0xC5, 0x9A, 0xC5, 0x90, 0xC5, 0xB5, 0xC5, 0xA1, 0xC5, 0xA4, 0xC5, 0xB1, 0xC5, 0xA0, 0xC5, 0x8D, 0xC5, 0xAC, 0xC5, 0xAB, 0xC5, 0xB1, 0xC5, 0x08, 0x0C};
		long Menu_UpdateHint = memstr(key,sizeof(key),buffer,len);
		if(Menu_UpdateHint!=-1)
		{
			//DbgPrint(L"%X",buffer[Menu_UpdateHint-149]);
			//buffer[aio_toobar_add+95] = 0x0F;
			if(buffer[Menu_UpdateHint-150]==0x82 && buffer[Menu_UpdateHint-149]==0xB7)
			{
				buffer[Menu_UpdateHint-150] = 0x81;
				//DbgPrint(L"�˵��޸����");
			}
		}

		BYTE PageSafeUpdate[] = {0xC7, 0x45, 0xFC, 0x21, 0x00, 0x00};//C7 45 FC 21 00 00
		long ConfigCenter = MemorySearch(L"ConfigCenter.dll",PageSafeUpdate, sizeof(PageSafeUpdate));
		//DbgPrint(L"ConfigCenter %X",ConfigCenter);
		if(ConfigCenter!=-1)
		{
			//DbgPrint(L"%X %X %X",ConfigCenter,ConfigCenter - 0x1A,*(BYTE*)( ConfigCenter + 0xC0 ));
			long start = ConfigCenter - 0x1A;
			long end = ConfigCenter + 0xC0;
			if( *(BYTE*)start == 0x68 && *(BYTE*)end == 0x68 )
			{
				WriteJMP(start,end);
				//DbgPrint(L"ConfigCenter�޸����");
			}
			//WriteProcessMemory(g_process,(void*)(IM_1), &patch, sizeof(patch), NULL);
		}
	}
}