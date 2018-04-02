function [sample] = GetSample(vector_source, offset, count)    
    
    if offset <= 0
        error("out of range")
    end

    sample_end = offset + count - 1;
    
    if sample_end > length(vector_source)
        error("out of range");
    end
    
    sample = vector_source(offset : sample_end);
    
end