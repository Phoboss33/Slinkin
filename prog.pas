var
  i, size: byte;
  randValue1: Smallint;
  randValue2: Shortint;
  randValue3: Longint;
  randValue4: Longword;
  randValue5: Int64;
  randValue6: Byte;
  randValue7: Word;
  randValue8: Cardinal;
  randValue9: QWord;
  randValue10: Char;
  randValue11: Boolean;
  choice: string;
  
begin
  writeln('Enter type (Smallint, Shortint, Longint, Longword, Int64, Byte, Word, Cardinal, QWord, Char, Boolean):');
  readln(choice);

  if choice = 'Smallint' then begin
    size := SizeOf(Smallint);
    randValue1 := 0;
    
    for i := size-1 downto 0 do randValue1 := (randValue1 shl 8) + Random(256);
    writeln('Type: Smallint');
    writeln('Lower: ', Low(Smallint));
    writeln('Upper: ', High(Smallint));
    writeln('Size in bytes: ', SizeOf(Smallint));
    writeln('Random value: ', randValue1);
    
    if randValue1 = Low(Smallint) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue1));
    if randValue1 = High(Smallint) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue1));
    writeln('In Memory: ', PByte(@randValue1)^, ' ', (PByte(@randValue1) + 1)^);
  end
  else if choice = 'Shortint' then begin
    size := SizeOf(Shortint);
    randValue2 := 0;
    
    for i := size-1 downto 0 do randValue2 := (randValue2 shl 8) + Random(256);
    writeln('Type: Shortint');
    writeln('Lower: ', Low(Shortint));
    writeln('Upper: ', High(Shortint));
    writeln('Size in bytes: ', SizeOf(Shortint));
    writeln('Random value: ', randValue2);
    
    if randValue2 = Low(Shortint) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue2));
    if randValue2 = High(Shortint) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue2));
    writeln('In Memory: ', PByte(@randValue2)^);
  end
  else if choice = 'Longint' then begin
    size := SizeOf(Longint);
    randValue3 := 0;
    
    for i := size-1 downto 0 do randValue3 := (randValue3 shl 8) + Random(256);
    writeln('Type: Longint');
    writeln('Lower: ', Low(Longint));
    writeln('Upper: ', High(Longint));
    writeln('Size in bytes: ', SizeOf(Longint));
    writeln('Random value: ', randValue3);
    
    if randValue3 = Low(Longint) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue3));
    if randValue3 = High(Longint) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue3));
    writeln('In Memory: ', PByte(@randValue3)^, ' ', (PByte(@randValue3) + 1)^, ' ', (PByte(@randValue3) + 2)^, ' ', (PByte(@randValue3) + 3)^);
  end
  else if choice = 'Longword' then begin
    size := SizeOf(Longword);
    randValue4 := 0;
    
    for i := size-1 downto 0 do randValue4 := (randValue4 shl 8) + Random(256);
    writeln('Type: Longword');
    writeln('Lower: ', Low(Longword));
    writeln('Upper: ', High(Longword));
    writeln('Size in bytes: ', SizeOf(Longword));
    writeln('Random value: ', randValue4);
    
    if randValue4 = Low(Longword) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue4));
    if randValue4 = High(Longword) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue4));
    writeln('In Memory: ', PByte(@randValue4)^, ' ', (PByte(@randValue4) + 1)^, ' ', (PByte(@randValue4) + 2)^, ' ', (PByte(@randValue4) + 3)^);
  end
  else if choice = 'Int64' then begin
    size := SizeOf(Int64);
    randValue5 := 0;
    
    for i := size-1 downto 0 do randValue5 := (randValue5 shl 8) + Random(256);
    writeln('Type: Int64');
    writeln('Lower: ', Low(Int64));
    writeln('Upper: ', High(Int64));
    writeln('Size in bytes: ', SizeOf(Int64));
    writeln('Random value: ', randValue5);
    
    if randValue5 = Low(Int64) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue5));
    if randValue5 = High(Int64) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue5));
    write('In Memory:'); 
    for i := 0 to size - 1 do write(' ',PByte(@randValue5)[i]);
    //writeln('In Memory: ', PByte(@randValue5)^, ' ', (PByte(@randValue5) + 1)^, ' ', (PByte(@randValue5) + 2)^, ' ', (PByte(@randValue5) + 3)^, ' ', (PByte(@randValue5) + 4)^, ' ', (PByte(@randValue5) + 5)^, ' ', (PByte(@randValue5) + 6)^, ' ', (PByte(@randValue5) + 7)^);
  end
  else if choice = 'Byte' then begin
    size := SizeOf(Byte);
    randValue6 := 0;
    
    for i := size-1 downto 0 do randValue6 := (randValue6 shl 8) + Random(256);
    writeln('Type: Byte');
    writeln('Lower: ', Low(Byte));
    writeln('Upper: ', High(Byte));
    writeln('Size in bytes: ', SizeOf(Byte));
    writeln('Random value: ', randValue6);
    
    if randValue6 = Low(Byte) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue6));
    if randValue6 = High(Byte) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue6));
    writeln('Memory contents: ', PByte(@randValue6)^);
  end
  else if choice = 'Word' then begin
    size := SizeOf(Word);
    randValue7 := 0;
    
    for i := size-1 downto 0 do randValue7 := (randValue7 shl 8) + Random(256);
    writeln('Type: Word');
    writeln('Lower: ', Low(Word));
    writeln('Upper: ', High(Word));
    writeln('Size in bytes: ', SizeOf(Word));
    writeln('Random value: ', randValue7);
    
    if randValue7 = Low(Word) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue7));
    if randValue7 = High(Word) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue7));
    writeln('In Memory: ', PByte(@randValue7)^, ' ', (PByte(@randValue7) + 1)^);
  end
  else if choice = 'Cardinal' then begin
    size := SizeOf(Cardinal);
    randValue8 := 0;
    
    for i := size-1 downto 0 do randValue8 := (randValue8 shl 8) + Random(256);
    writeln('Type: Cardinal');
    writeln('Lower: ', Low(Cardinal));
    writeln('Upper: ', High(Cardinal));
    writeln('Size in bytes: ', SizeOf(Cardinal));
    writeln('Random value: ', randValue8);
    
    if randValue8 = Low(Cardinal) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue8));
    if randValue8 = High(Cardinal) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue8));
    writeln('In Memory: ', PByte(@randValue8)^, ' ', (PByte(@randValue8) + 1)^, ' ', (PByte(@randValue8) + 2)^, ' ', (PByte(@randValue8) + 3)^);
  end
  else if choice = 'QWord' then begin
    size := SizeOf(QWord);
    randValue9 := 0;
    
    for i := size-1 downto 0 do randValue9 := (randValue9 shl 8) + Random(256);
    writeln('Type: QWord');
    writeln('Lower: ', Low(QWord));
    writeln('Upper: ', High(QWord));
    writeln('Size in bytes: ', SizeOf(QWord));
    writeln('Random value: ', randValue9);
    
    if randValue9 = Low(QWord) then writeln('Previous value: Overflow')
    else writeln('Previous value: ', Pred(randValue9));
    if randValue9 = High(QWord) then writeln('Next value: Overflow')
    else writeln('Next value: ', Succ(randValue9));
    writeln('In Memory: ', PByte(@randValue9)^, ' ', (PByte(@randValue9) + 1)^, ' ', (PByte(@randValue9) + 2)^, ' ', (PByte(@randValue9) + 3)^, ' ', (PByte(@randValue9) + 4)^, ' ', (PByte(@randValue9) + 5)^, ' ', (PByte(@randValue9) + 6)^, ' ', (PByte(@randValue9) + 7)^);
  end
  else if choice = 'Char' then begin
    size := SizeOf(Char);
    randValue10 := Char(Random(256));
    
    writeln('Type: Char');
    writeln('Lower: #',  Ord(Low(Char)));
    writeln('Upper: #', Ord(High(Char)));
    writeln('Size in bytes: ', SizeOf(Char));
    writeln('Random value: ', '#', Ord(randValue10));
    
    if randValue10 = Char(Low(Byte)) then writeln('Previous value: Overflow')
    else writeln('Previous value: #', Ord(Pred(randValue10)));
    if randValue10 = Char(High(Byte)) then writeln('Next value: Overflow')
    else writeln('Next value: #', Ord(Succ(randValue10)));
    writeln('In Memory: ', PByte(@randValue10)^);
  end
  else if choice = 'Boolean' then begin
    size := SizeOf(Boolean);
    randValue11 := Boolean(Random(2));
    
    writeln('Type: Boolean');
    writeln('Lower: ', Low(Boolean));
    writeln('Upper: ', High(Boolean));
    writeln('Size in bytes: ', SizeOf(Boolean));
    writeln('Random value: ', randValue11);
    
    if randValue11 = False then writeln('Previous value: Overflow')
    else writeln('Previous value: ', not randValue11);
    if randValue11 = True then writeln('Next value: Overflow')
    else writeln('Next value: ', not randValue11);
    writeln('In Memory: ', PByte(@randValue11)^);
  end
  else writeln('Error');
end.

