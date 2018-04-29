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
handles.data = zeros(1,1);
handles.ofs = 1;
handles.n = 0;
handles.sl = 1;
handles.pc = 1;
handles.sr = [];
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
filename = get(handles.fileedit, 'string');
handles.data = LoadData();
handles.n = length(handles.data);
guidata(hObject,handles);

axes(handles.tsaxes);
plot(handles.data);



function offsetedit_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function offsetedit_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in processbutton.
function processbutton_Callback(hObject, eventdata, handles)
handles.ofs = str2double(get(handles.offsetedit, 'string'));
handles.sl = str2double(get(handles.lenedit, 'string'));
handles.pc = str2double(get(handles.prededit, 'string'));
n = length(handles.data);

if  handles.ofs<1 || handles.ofs>n
    handles.ofs=1;
end

if handles.sl+handles.ofs>n || handles.sl<1
    handles.ofs=1;
end

if handles.pc < 1
    handles.pc = 1;
end

Xj = handles.data(handles.ofs:handles.ofs-1+handles.sl);
[st,preds,nsr] = ProcessTs(Xj,handles.pc,handles.sr,10);

switch st
    case 0
        %plot(Xj);
        TS = length(preds)-1;
        plot(1:handles.n,handles.data,handles.ofs:handles.ofs+TS,preds);
        msgbox('Ok','Success');
    case 1
        [counts, binCenters] = hist(Xj);
        bar(binCenters, counts, 'BarWidth', 1);
        msgbox('Not normal distribution','Error');
    case 2
        plot(Xj);
        msgbox('Error in Shewhart maps','Error');
end

guidata(hObject,handles);


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
