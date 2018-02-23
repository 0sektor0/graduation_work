function IsNormal = CheckNormality(sample)
    if ShapiroWeakCriterion(sample) || HegazyGreenCriterion(sample, 0.05) || GiriCriterion(sample, 0.05)
        IsNormal = true;
    else
        IsNormal = false;
    end
end

