function varargout = gui(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before gui is made visible.
function gui_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
handles.time_series = zeros(1,1);       %временной ряд
handles.sample_offset = 1;              %сдвиг начала выборки
handles.ts_size = 0;                    %размер временного ряда
handles.sample_size = 1;                %размер выюорки
handles.predictions_count = 1;          %число предсказаний
handles.system_criterians = [];         %критерии системы
handles.sc_size = 10;                   %размер критериев
handles.sigma = 0.01;
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = gui_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;



function fileedit_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function fileedit_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in filebutton.
function filebutton_Callback(hObject, eventdata, handles)
set(handles.criterianslistbox,'string',{});

filename = get(handles.fileedit, 'string');
if exist(filename)
    handles.time_series = LoadData(filename);
    handles.ts_size = length(handles.time_series);
    guidata(hObject,handles);

    axes(handles.tsaxes);
    plot(handles.time_series);
else 
    msgbox('File dosent exist','Error');
end



function offsetedit_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function offsetedit_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function lenedit_Callback(hObject, eventdata, handles)
% hObject    handle to lenedit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of lenedit as text
%        str2double(get(hObject,'String')) returns contents of lenedit as a double


% --- Executes during object creation, after setting all properties.
function lenedit_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function prededit_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function prededit_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function criterianssizeedit_Callback(hObject, eventdata, handles)
% hObject    handle to criterianssizeedit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of criterianssizeedit as text
%        str2double(get(hObject,'String')) returns contents of criterianssizeedit as a double


% --- Executes during object creation, after setting all properties.
function criterianssizeedit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to criterianssizeedit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in criteriancheckbox.
function criteriancheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to criteriancheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of criteriancheckbox


% --- Executes on selection change in criterianslistbox.
function criterianslistbox_Callback(hObject, eventdata, handles)
index_selected = get(hObject,'Value');
if length(handles.system_criterians) >= index_selected
    DrawCriterian(handles.system_criterians(index_selected));
end


% --- Executes during object creation, after setting all properties.
function criterianslistbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to criterianslistbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
