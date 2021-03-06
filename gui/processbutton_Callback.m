% --- Executes on button press in processbutton.
function processbutton_Callback(hObject, eventdata, handles)

handles.sample_offset = str2double(get(handles.offsetedit, 'string'));
handles.sample_size = str2double(get(handles.lenedit, 'string'));
handles.predictions_count = str2double(get(handles.prededit, 'string'));
handles.sr_size = str2double(get(handles.criterianssizeedit, 'string'));
n = length(handles.time_series);

if  handles.sample_offset<1 || handles.sample_offset>n
    handles.sample_offset=1;
end

if handles.sample_size+handles.sample_offset>n || handles.sample_size<1
    handles.sample_offset=1;
end

if handles.predictions_count < 1
    handles.predictions_count = 1;
end

Xj = handles.time_series(handles.sample_offset:handles.sample_offset-1+handles.sample_size);
[st,preds,nsr] = ProcessTsSr(Xj, handles.predictions_count, handles.system_criterians, handles.sr_size, handles.sigma);

switch st.type
    case 0
        %plot(Xj);
        TS = length(preds)-1;
        plot(1:handles.ts_size,handles.time_series,handles.sample_offset:handles.sample_offset+TS,preds);
        msgbox(st.text,'Success');
    case 1
        [counts, binCenters] = hist(Xj);
        bar(binCenters, counts, 'BarWidth', 1);
        msgbox(st.text,'Error');
    case 2
        plot(Xj);
        handles.system_criterians = AddCriterian(handles.system_criterians, nsr);
        msgbox(st.text,'Error');
end

new_str= num2cell(1 : length(handles.system_criterians));
set(handles.criterianslistbox,'string',new_str);

guidata(hObject,handles);